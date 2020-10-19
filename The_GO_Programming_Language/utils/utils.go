package utils

import (
	"fmt"
	"log"
	"net"
	"reflect"
	"strconv"
	"strings"
)

type NilPtr struct{}
type NotValid struct{}
type NotStruct struct{}
type NotPointer struct{}

func (n NotStruct) Error() string {
	return "Not a struct"
}

func (n NotPointer) Error() string {
	return "Not a pointer"
}

func (n NotValid) Error() string {
	return "Not Valid"
}

func (n NilPtr) Error() string {
	return "Nil Pointer"
}

type SetComplete interface {
	SetComplete()
}

func SetReflectValue(t reflect.Type, v reflect.Value, s string) error {
	var b bool
	var i int64
	var u uint64
	var f float64
	var err error

	base := 10

	// the true base is implied by the string's prefix
	// only support 0x and 0X here
	if strings.HasPrefix(s, "0x") || strings.HasPrefix(s, "0X") {
		base = 0
	}

	switch t.Kind() {
	case reflect.Bool:
		if b, err = strconv.ParseBool(s); err != nil {
			return err
		}
		v.SetBool(b)
	case reflect.Int:
		if i, err = strconv.ParseInt(s, base, 0); err != nil {
			return err
		}
		v.SetInt(i)
	case reflect.Int8:
		if i, err = strconv.ParseInt(s, base, 8); err != nil {
			return err
		}
		v.SetInt(i)
	case reflect.Int16:
		if i, err = strconv.ParseInt(s, base, 16); err != nil {
			return err
		}
		v.SetInt(i)
	case reflect.Int32:
		if i, err = strconv.ParseInt(s, base, 32); err != nil {
			return err
		}
		v.SetInt(i)
	case reflect.Int64:
		if i, err = strconv.ParseInt(s, base, 64); err != nil {
			return err
		}
		v.SetInt(i)
	case reflect.Uint:
		if u, err = strconv.ParseUint(s, base, 0); err != nil {
			return err
		}
		v.SetUint(u)
	case reflect.Uint8:
		if u, err = strconv.ParseUint(s, base, 8); err != nil {
			return err
		}
		v.SetUint(u)
	case reflect.Uint16:
		if u, err = strconv.ParseUint(s, base, 16); err != nil {
			return err
		}
		v.SetUint(u)
	case reflect.Uint32:
		if u, err = strconv.ParseUint(s, base, 32); err != nil {
			return err
		}
		v.SetUint(u)
	case reflect.Uint64:
		if u, err = strconv.ParseUint(s, base, 64); err != nil {
			return err
		}
		v.SetUint(u)
	case reflect.Float32:
		if f, err = strconv.ParseFloat(s, 32); err != nil {
			return err
		}
		v.SetFloat(f)
	case reflect.Float64:
		if f, err = strconv.ParseFloat(s, 64); err != nil {
			return err
		}
		v.SetFloat(f)
	case reflect.String:
		v.SetString(s)
	}
	return nil
}

func SetStruct(vs map[string]string, x interface{}) error {

	if reflect.TypeOf(x).Kind() != reflect.Ptr {
		return NotPointer{}
	}

	vx := reflect.ValueOf(x).Elem()
	tx := reflect.TypeOf(x).Elem()

	if tx.Kind() != reflect.Struct {
		return NotStruct{}
	}

	for k, v := range vs {
		// Handle the export field in struct, usuall it's lowercase in vs
		// "key" => "Key"
		evx := vx.FieldByName(strings.Title(k))
		if !evx.IsValid() {
			// Try again with no title key
			if evx = vx.FieldByName(k); !evx.IsValid() {
				log.Printf("Failed to find %s in struct %v.\n", k, tx)
				continue
			}
		}

		if err := SetReflectValue(evx.Type(), evx, v); err != nil {
			log.Printf("Failed to Set %s in struct %v due to %v.\n", k, tx, err)
		}
	}

	if reflect.PtrTo(tx).Implements(reflect.TypeOf((*SetComplete)(nil)).Elem()) {
		if m := reflect.ValueOf(x).MethodByName("SetComplete"); m.IsValid() {
			m.Call(nil)
		}
	}

	return nil
}

func DumpStruct(x interface{}) string {
	vx := reflect.Indirect(reflect.ValueOf(x))

	// Refer doc, it's Nil Pointer
	if !vx.IsValid() {
		return "Dump Error:" + NilPtr{}.Error()
	}

	tx := vx.Type()

	if tx.Kind() != reflect.Struct {
		return "Dump Error" + NotStruct{}.Error()
	}

	var dump = []string{"{"}

	for i := 0; i < tx.NumField(); i++ {
		ttx := tx.Field(i)
		vvx := vx.Field(i)
		if vvx.Type().Kind() == reflect.Interface {
			dump = append(dump, fmt.Sprintf("%s: %v", ttx.Name, vvx.Elem()))
		} else 	if vvx.Type().Kind() == reflect.Ptr {
			dump = append(dump, fmt.Sprintf("%s: %v", ttx.Name, vvx.Elem()))
		} else {
			dump = append(dump, fmt.Sprintf("%s: %v", ttx.Name,  vvx))
		}
	}
	return strings.Join(append(dump, "}"), " ")
}

func OutboundIP() net.IP {
	var localAddr *net.UDPAddr
	// gfw
	for _, host := range []string{"8.8.8.8:80", "114.114.114.114:80"} {
		conn, err := net.Dial("udp", host)
		if err != nil {
			log.Fatal(err)
		} else {
			// .(Type) Type Assertions
			localAddr = conn.LocalAddr().(*net.UDPAddr)
		}
		conn.Close()
		if localAddr != nil && !localAddr.IP.IsUnspecified() {
			return localAddr.IP
		}
	}
	return nil
}
