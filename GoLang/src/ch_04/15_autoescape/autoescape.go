/**************************************************
	> File Name:  autoescape.go
	> Author:     Leuckart
	> Time:       2021-01-24 01:06
**************************************************/

package main

import (
	"html/template"
	"log"
	"os"
)

type Data struct {
	A string
	B template.HTML // template.HTML 可避免模板自动转义受信任的 HTML 数据
}

func main() {
	const templ = `<p>A: {{.A}}</p><p>B: {{.B}}</p>`
	escape := template.Must(template.New("escape").Parse(templ))

	var data Data = Data{"<b>Hello!</b>", "<b>Hello!</b>"}
	if err := escape.Execute(os.Stdout, data); err != nil {
		log.Fatal(err)
	}
}
