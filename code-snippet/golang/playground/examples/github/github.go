// 包: Github API数据结构定义, https://developer.github.com/v3/
package github

import (
	"encoding/json"
	"fmt"
	"net/http"
	"net/url"
	"strings"
	"time"
)

const (
	IssuesURL = "https://api.github.com/search/issues"
)

type IssueSearchResult struct {
	TotalCount int `json:"total_count"`
	Items      []*Issue
}

// Issue
type Issue struct {
	Number    int
	HTMLURL   string `json:"html_url"`
	Title     string
	State     string
	User      *User
	CreatedAt time.Time `json:"created_at"`
	Body      string    // Markdown格式
}

// User
type User struct {
	Login   string
	HTMLURL string `json:"html_url"`
}

// SearchIssue
func SearchIssue(terms []string) (*IssueSearchResult, error) {
	q := url.QueryEscape(strings.Join(terms, " "))
	queryUrl := IssuesURL + "?q=" + q
	fmt.Println(queryUrl)
	resp, err := http.Get(queryUrl)
	if err != nil {
		return nil, err
	}

	if resp.StatusCode != http.StatusOK {
		resp.Body.Close()
		return nil, fmt.Errorf("search query failed: %s", resp.Status)
	}

	var result IssueSearchResult
	if err := json.NewDecoder(resp.Body).Decode(&result); err != nil {
		resp.Body.Close()
		return nil, err
	}
	resp.Body.Close()
	return &result, nil
}
