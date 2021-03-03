/**************************************************
	> File Name:  ast.go
	> Author:     Leuckart
	> Time:       2021-01-25 05:12
**************************************************/

package eval

type Var string

type literal float64

type unary struct {
	op rune // '+' or '-'
	x  Expr
}

type binary struct {
	op   rune // '+', '-', '*' or '/'
	x, y Expr
}

type call struct {
	fn   string // 'pow', 'sin' or 'sqrt'
	args []Expr
}

type Expr interface {
	Eval(env Env) float64
	Check(vars map[Var]bool) error
}
