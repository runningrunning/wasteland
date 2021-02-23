package github

import (
	"encoding/json"
	"fmt"
	"net/http"
	"net/url"
	"strings"
)

// SearchIssues queries the GitHub issues tracker.
// others are non query parameters in https://docs.github.com/en/rest/reference/search
func SearchIssues(terms, others []string) (*IssuesSearchResult, error) {
	q := url.QueryEscape(strings.Join(terms, " "))
	o := strings.Join(others, "&")

	if o != "" {
		o = "&" + o
	}

	// fmt.Println("Issue url is ", IssuesURL + "?q=" + q + o)

	resp, err := http.Get(IssuesURL + "?q=" + q + o)
	if err != nil {
		return nil, err
	}

	defer resp.Body.Close()
	if resp.StatusCode != http.StatusOK {
		return nil, fmt.Errorf("search query failed: %s", resp.Status)
	}

	var result IssuesSearchResult
	if err := json.NewDecoder(resp.Body).Decode(&result); err != nil {
		return nil, err
	}

	return &result, nil
}
