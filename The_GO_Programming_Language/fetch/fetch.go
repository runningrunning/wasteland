/* -*- Mode: go; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
package fetch

import (
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	"strings"
	"time"
)

func toUrl(url string) string {
	if !strings.HasPrefix(url, "http://") {
		return "http://" + url
	}
	return url
}

func FetchStr(url string) (string, error) {
	url = toUrl(url)

	resp, err := http.Get(url)

	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
		return "", err
	}

	out, err := ioutil.ReadAll(resp.Body)

	defer resp.Body.Close()

	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: reading %s: %v\n", url, err)
		return "", err
	}
	return string(out), err
}

func FetchIO(url string, out io.Writer) error {
	url = toUrl(url)

	resp, err := http.Get(url)

	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
		return err
	}

	_, err = io.Copy(out, resp.Body)
	defer resp.Body.Close()

	if err != nil {
		fmt.Fprintf(os.Stderr, "copy: copy %s: %v\n", url, err)
		return err
	}

	return nil
}

func FetchIOWithStatus(url string, out io.Writer) error {
	url = toUrl(url)

	resp, err := http.Get(url)

	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: %v\n", err)
		return err
	}

	defer resp.Body.Close()

	_, err = io.Copy(out, resp.Body)

	if err == nil {
		_, err = out.Write([]byte(fmt.Sprintf("response: %s: %v\n", url, resp.Status)))
	}

	if err != nil {
		fmt.Fprintf(os.Stderr, "fetch: %s: %v\n", url, err)
		return err
	}

	return nil
}

func FetchChan(url string, ch chan<- string) {
	url = toUrl(url)

	start := time.Now()
	resp, err := http.Get(url)

	if err != nil {
		ch <- fmt.Sprint(err)
		return
	}

	nbytes, err := io.Copy(ioutil.Discard, resp.Body)
	resp.Body.Close()

	if err != nil {
		ch <- fmt.Sprintf("while reading %s: %v", url, err)
	}

	secs := time.Since(start).Seconds()
	ch <- fmt.Sprintf("%.2fs %7d %s", secs, nbytes, url)
}
