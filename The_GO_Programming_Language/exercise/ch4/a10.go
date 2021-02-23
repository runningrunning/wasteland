package main

import (
	"fmt"
	"log"
	"os"
	"tgpl/github"
	"time"
)

func out(item *github.Issue) {
	fmt.Printf("#%-5d %9.9s %.30v %.55s\n",
		item.Number, item.User.Login, item.CreatedAt, item.Title)
}

func outNormal(result *github.IssuesSearchResult) {
	for _, item := range result.Items {
		out(item)
	}
}

func outByAge(result *github.IssuesSearchResult) {
	start := time.Now()
	lessOneMonth := start.AddDate(0, -1, 0)
	lessOneYear := start.AddDate(-1, 0, 0)
	// categories := make([][]*github.Issue, 3)
	categories := [3][]*github.Issue{}

	addIn := func(in int, i *github.Issue) {
		if categories[in] == nil {
			// categories[in] = make([]*github.Issue, 0)
			categories[in] = []*github.Issue{}
		}
		categories[in] = append(categories[in], i)
	}

	for _, item := range result.Items {
		if item.CreatedAt.Before(lessOneYear) {
			addIn(2, item)
		} else if item.CreatedAt.Before(lessOneMonth) {
			addIn(1, item)
		} else {
			addIn(0, item)
		}
	}

	for i, items := range categories {
		if i == 0 {
			fmt.Println("Less than One Month")
		} else if i == 1 {
			fmt.Println("Less than One Year")
		} else {
			fmt.Println("More than One Year")
		}

		for _, item := range items {
			out(item)
		}
	}
}

func main() {
	result, err := github.SearchIssues(os.Args[1:], nil)
	if err != nil {
		log.Fatal(err)
	}
	// fmt.Printf("%d issues:\n", result.TotalCount)
	// outNormal(result)
	// outByAge(result)
	// github.Report(result)
	github.HTMLReport(result, os.Stdout)
}
