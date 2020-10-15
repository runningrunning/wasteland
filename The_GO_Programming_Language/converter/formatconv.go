package converter

import (
	"fmt"
	"os"
	"strconv"
)

type Celsius float64
type Fahrenheit float64
type Kelvin float64
type Kilogram float64
type Pound float64
type Feet float64
type Meter float64
type Inch float64

const (
	AbsoluteZeroC   Celsius = -273.15
	FreezingC       Celsius = 0
	BoilingC        Celsius = 100
	KelvinZeroK     Kelvin  = 0
	KilogramToPound float64 = 2.20462262185
	FeetToMeter     float64 = 0.3048
	FeetToInch      float64 = 12
)

type Format interface {
	String() string
	Type() string
	Convert(string) Format
}

func (c Celsius) String() string {
	return fmt.Sprintf("%gC", c)
}

func (c Celsius) Type() string {
	return "celsius"
}

func (c Celsius) Convert(to string) Format {
	switch to {
	case "fahrenheit":
		return CToF(c)
	case "kelvin":
		return CToK(c)
	}
	return nil
}

func (f Fahrenheit) String() string {
	return fmt.Sprintf("%gF", f)
}

func (f Fahrenheit) Type() string {
	return "fahrenheit"
}

func (f Fahrenheit) Convert(to string) Format {
	switch to {
	case "celsius":
		return FToC(f)
	case "kelvin":
		return FToK(f)
	}
	return nil
}

func (k Kelvin) String() string {
	return fmt.Sprintf("%gK", k)
}

func (k Kelvin) Type() string {
	return "kelvin"
}

func (k Kelvin) Convert(to string) Format {
	switch to {
	case "celsius":
		return KToC(k)
	case "fahrenheit":
		return KToF(k)
	}
	return nil
}

func (k Kilogram) String() string {
	return fmt.Sprintf("%gKg", k)
}

func (k Kilogram) Type() string {
	return "kilogram"
}

func (k Kilogram) Convert(to string) Format {
	if to == "pound" {
		return Pound(float64(k) * KilogramToPound)
	}
	return nil
}

func (p Pound) String() string {
	return fmt.Sprintf("%gLb", p)
}

func (p Pound) Type() string {
	return "pound"
}

func (p Pound) Convert(to string) Format {
	if to == "kilogram" {
		return Kilogram(float64(p) / KilogramToPound)
	}
	return nil
}

func (f Feet) String() string {
	return fmt.Sprintf("%gft", f)
}

func (f Feet) Type() string {
	return "feet"
}

func (f Feet) Convert(to string) Format {
	switch to {
	case "meter":
		return Meter(float64(f) * FeetToMeter)
	case "inch":
		return Inch(float64(f) * FeetToInch)
	}
	return nil
}

func (i Inch) String() string {
	return fmt.Sprintf("%gin", i)
}

func (i Inch) Type() string {
	return "inch"
}

func (i Inch) Convert(to string) Format {
	switch to {
	case "meter":
		return Feet(float64(i) / FeetToInch).Convert("meter")
	case "feet":
		return Feet(float64(i) / FeetToInch)
	}
	return nil
}

func (m Meter) String() string {
	return fmt.Sprintf("%gm", m)
}

func (m Meter) Type() string {
	return "meter"
}

func (m Meter) Convert(to string) Format {
	switch to {
	case "feet":
		return Feet(float64(m) / FeetToMeter)
	case "inch":
		return Feet(float64(m) / FeetToMeter).Convert("inch")
	}
	return nil
}

func ToFormat(to, value string) Format {
	v, err := strconv.ParseFloat(value, 64)

	if err != nil {
		fmt.Fprintf(os.Stderr, "invalid value %s: %v.\n", value, err)
		return nil
	}

	switch to {
	case "celsius":
		return Celsius(v)
	case "fahrenheit":
		return Fahrenheit(v)
	case "kelvin":
		return Kelvin(v)
	case "kilogram":
		return Kilogram(v)
	case "pound":
		return Pound(v)
	case "feet":
		return Feet(v)
	case "meter":
		return Meter(v)
	case "inch":
		return Inch(v)
	}

	return nil
}

// Can not declar a constant map or any aggregate type
// https://stackoverflow.com/questions/18342195/how-to-declare-a-constant-map-in-golang
var abbr = map[string]string{
	"c":  "celsius",
	"f":  "fahrenheit",
	"k":  "kelvin",
	"kg": "kilogram",
	"lb": "pound",
	"ft": "feet",
	"m":  "meter",
	"in": "inch",
}

func Convert(from, to, value string) {
	if val, ok := abbr[from]; ok {
		from = val
	}

	if val, ok := abbr[to]; ok {
		to = val
	}

	f := ToFormat(from, value)

	if f == nil {
		fmt.Fprintf(os.Stderr, "Invalid input: from %s %s to %s.\n", from, value, to)
	}

	if from == to {
		fmt.Fprintf(os.Stdout, "Not convert: same type %s %s.\n", from, to)
	}

	r := f.Convert(to)

	if r == nil {
		fmt.Fprintf(os.Stderr, "Can not convert from %s %s to %s.\n", from, value, to)
		return
	}

	fmt.Fprintf(os.Stdout, "Convert %s to %s.\n", f, r)
}

func Enumerate(value string) {
	for _, f := range abbr {
		for _, t := range abbr {
			v := ToFormat(f, value)
			if r := v.Convert(t); r != nil {
				fmt.Fprintf(os.Stdout, "Convert %s to %s.\n", v, r)
			}
		}
	}
}
