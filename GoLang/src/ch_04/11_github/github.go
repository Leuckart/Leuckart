/**************************************************
	> File Name:  github.go
	> Author:     Leuckart
	> Time:       2021-01-18 18:14
**************************************************/

package github

import "time"

const IssuesURL = "https://api.github.com/search/issues"

// 标签值指定 Go 结构体成员对应 JSON 中字段的名字
type IssuesSearchResult struct {
	TotalCount int `json:"total_count"`
	Items      []*Issue
}

// Unmarshal 阶段 JSON 字段关联到 Go 结构体成员时是忽略名称大小写的, 所以只有存在 '_' 时需要使用 '成员标签定义'
type User struct {
	Login   string
	HTMLURL string `json:"html_url"`
}

type Issue struct {
	Number    int
	HTMLURL   string `json:"html_url"`
	Title     string
	State     string
	User      *User
	CreatedAt time.Time `json:"created_at"`
	Body      string
}
