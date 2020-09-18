package github

import (
	"fmt"
	"testing"
)

// 搜索GitHub中Issue
func TestSearchIssue(t *testing.T) {
	terms := []string{"HBase"}
	result, err := SearchIssue(terms)
	if err != nil {
		t.Error(err)
	}
	fmt.Printf("%d issues:\n", result.TotalCount)
	for _, item := range result.Items {
		fmt.Printf("#%-5d %9.9s %.55s\n",
			item.Number, item.User.Login, item.Title)
	}
}
