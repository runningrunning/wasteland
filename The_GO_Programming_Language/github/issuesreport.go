package github

import (
	htemplate "html/template"
	"log"
	"os"
	"text/template"
	"time"
)

const templ = `{{.TotalCount}} issues:
{{range .Items}}--------------------------------------------------------------------------------
Number: {{.Number}}
User:   {{.User.Login}}
Age:    {{.CreatedAt | daysAgo}} days
State:  {{.State}}
Link:   {{.HTMLURL}}
Title:  {{.Title | printf "%.64s"}}
{{end}}`

func daysAgo(t time.Time) int {
	return int(time.Since(t).Hours() / 24)
}

var report = template.Must(template.New("issuelist").
	Funcs(template.FuncMap{"daysAgo": daysAgo}).
	Parse(templ))

func Report(result *IssuesSearchResult) {
	if err := report.Execute(os.Stdout, result); err != nil {
		log.Fatal(err)
	}
}

var issueList = htemplate.Must(htemplate.New("issuelist").Parse(`
<h1>{{.TotalCount}} issues</h1>
<table>
<tr style='text-align:left'>
<th>#</th>
<th>State</th>
<th>User</th>
<th>Title</th>
</tr>
{{range .Items}}
<tr>
<td><a href='{{.HTMLURL}}'>{{.Number}}</a></td>
<td>{{.State}}</td>
<td><a href='{{.User.HTMLURL}}'>{{.User.Login}}</a></td>
<td><a href='{{.HTMLURL}}'>{{.Title}}</a></td>
</tr>
{{end}}
</table>
`))

func HTMLReport(result *IssuesSearchResult) {
	if err := issueList.Execute(os.Stdout, result); err != nil {
		log.Fatal(err)
	}
}
