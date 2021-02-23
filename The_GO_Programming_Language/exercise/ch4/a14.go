package main

import (
	"fmt"
	"net/http"
	"net/url"
	"strconv"
	"strings"
	"tgpl/github"
	"tgpl/server"
)

func link(form url.Values, page int) string {
	var query []string
	for k, v := range form {
		if k == "page" {
			query = append(query, "page="+strconv.Itoa(page))
		} else {
			query = append(query, k+"="+url.QueryEscape(v[0]))
		}
	}

	if form["page"] == nil {
		query = append(query, "page="+strconv.Itoa(page))
	}

	// fmt.Println(query, "/github?" + strings.Join(query, "&"))
	return "/github?" + strings.Join(query, "&")
}

func handleGitHub(w http.ResponseWriter, r *http.Request) {
	query := r.FormValue("query")
	page := r.FormValue("page")

	// Page start from 1
	pageNumber := 1

	if len(query) == 0 {
		fmt.Fprintf(w, "No query Supplied.")
		return
	}

	others := []string{"per_page=100"}

	if page != "" {
		pageNumber, _ = strconv.Atoi(page)
	}

	if pageNumber != 0 {
		others = append(others, "page="+strconv.Itoa(pageNumber))
	}

	if result, err := github.SearchIssues([]string{query}, others); err != nil {
		fmt.Fprintf(w, "Can not find anything for %s\n", query)
	} else {
		w.Header().Set("Content-Type", "text/html")
		if pageNumber > 1 {
			fmt.Fprintf(w, "<a href=%s>Pre</a>\n", link(r.Form, pageNumber-1))
		}

		if pageNumber < (result.TotalCount + 100 - 1) / 100  {
			fmt.Fprintf(w, "<a href=%s>Next</a>\n", link(r.Form, pageNumber+1))
		}

		github.HTMLReport(result, w)

	}
}

func main() {
	server.Server(map[string]server.Handler{"/github": handleGitHub})
}
