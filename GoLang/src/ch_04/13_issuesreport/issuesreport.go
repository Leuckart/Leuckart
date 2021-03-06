/**************************************************
	> File Name:  issuesreport.go
	> Author:     Leuckart
	> Time:       2021-01-24 00:53
**************************************************/

package main

import (
	"log"
	"os"
	"text/template"
	"time"

	"ch_04/11_github"
)

func daysAgo(t time.Time) int {
	return int(time.Since(t).Hours() / 24)
}

const templ = `{{.TotalCount}} issues:
{{range .Items}}-------------------------
Number: {{.Number}}
User:   {{.User.Login}}
Title:  {{.Title | printf "%.64s"}}
Age:    {{.CreatedAt | daysAgo}} days
{{end}}`

var report = template.Must(template.New("issuelist").
	Funcs(template.FuncMap{"daysAgo": daysAgo}).
	Parse(templ))

// ./issuesreport repo:golang/go is:open json decoder
func main() {
	result, err := github.SearchIssues(os.Args[1:])
	if err != nil {
		log.Fatal(err)
	}

	if err := report.Execute(os.Stdout, result); err != nil {
		log.Fatal(err)
	}
}
