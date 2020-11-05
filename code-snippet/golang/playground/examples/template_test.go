package examples

import (
	"os"
	"testing"
	"text/template"
	"time"

	"github.com/zhoujiagen/examples/github"
)

// 展示了模板语言: 动作, 循环, 函数
const textTemplate = `{{.TotalCount}} issues:
{{range .Items}}------------------------------------------------
Number: {{.Number}}
User: {{.User.Login}}
Title: {{.Title | printf "%.64s"}}
Age: {{.CreatedAt | daysAgo}} days
{{end}}`

func daysAgo(t time.Time) int {
	return int(time.Since(t).Hours() / 24)
}

var textReport = template.Must(template.New("issuelist").
	Funcs(template.FuncMap{"daysAgo": daysAgo}).
	Parse(textTemplate))

func TestTemplate(t *testing.T) {
	terms := []string{"HBase"}
	result, err := github.SearchIssue(terms)
	if err != nil {
		t.Error(err)
	}

	if err := textReport.Execute(os.Stdout, result); err != nil {
		t.Error(err)
	}
}
