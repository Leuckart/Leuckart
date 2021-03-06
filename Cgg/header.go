/**************************************************
	> File Name:  header.go
	> Author:     Leuckart
	> Time:       2021-02-28 22:32
**************************************************/

package main

type float float32

const FLOAT_SIZE = 32
const (
	TTYPE_IDENT = iota
	TTYPE_PUNCT
	TTYPE_NUMBER
	TTYPE_CHAR
	TTYPE_STRING
	// Only in CPP
	TTYPE_NEWLINE
	TTYPE_SPACE
	TTYPE_MACRO_PARAM
)

type Token struct {
	typ     int
	space   bool
	bol     bool
	file    string
	line    int
	column  int
	hideset *Dict
	// intends union
	sval     string
	punct    int
	c        byte
	position int
}

const (
	AST_LITERAL = iota + 256
	AST_STRING
	AST_LVAR
	AST_GVAR
	AST_FUNCALL
	AST_FUNC
	AST_DECL
	AST_INIT_LIST
	AST_ADDR
	AST_DEREF
	AST_IF
	AST_TERNARY
	AST_FOR
	AST_RETURN
	AST_COMPOUND_STMT
	AST_STRUCT_REF
	OP_EQ
	OP_NE
	OP_LE
	OP_GE
	OP_INC
	OP_DEC
	OP_LOGAND
	OP_LOGOR
	OP_ARROW
)

const (
	CTYPE_VOID int = iota
	CTYPE_CHAR
	CTYPE_SHORT
	CTYPE_INT
	CTYPE_LONG
	CTYPE_LLONG
	CTYPE_FLOAT
	CTYPE_DOUBLE
	CTYPE_LDOUBLE
	CTYPE_ARRAY
	CTYPE_PTR
	CTYPE_STRUCT
	CTYPE_FUNC
	// used only in parser
	CTYPE_STUB
)

type Ctype struct {
	typ  int
	size int
	// true if signed
	sig bool
	// pointer or array
	ptr *Ctype
	// array length
	len int
	// struct
	fields *Dict
	offset int
	// function
	rettype *Ctype
	params  []*Ctype
	hasva   bool
}

type Ast struct {
	typ   int
	ctype *Ctype
	// want to be "union"
	// Char, int, or long
	ival int
	// Float or double
	fval   float64
	flabel string

	// pseudo Union
	// String
	val    string
	slabel string
	// Local/Global variable
	varname string
	loff    int
	glabel  string
	// Binary operator
	left  *Ast
	right *Ast
	// Unary operator
	operand *Ast
	// Function call or function declaration
	fname string
	// Function call
	args       []*Ast
	paramtypes []*Ctype
	// Function declaration
	params    []*Ast
	localvars []*Ast
	body      *Ast
	// Declaration
	declvar  *Ast
	declinit *Ast
	// array or struct initializer
	initlist []*Ast
	totype   *Ctype
	// If statement or ternary operator
	cond *Ast
	then *Ast
	els  *Ast
	// For statement
	init *Ast
	//	cond *Ast
	step *Ast
	//	body *Ast
	// return
	retval *Ast
	// compound
	stmts []*Ast
	// StructRef
	struc *Ast
	field string // only for debug.go
}

type Env struct {
	vars    []*Ast
	next    *Env
	structs []*Ast
}
