/**************************************************
	> File Name:  cake_test.go
	> Author:     Leuckart
	> Time:       2021-01-26 01:33
**************************************************/

// go test -bench=.
package cake

import (
	"testing"
	"time"
	"fmt"
)

// https://github.com/golang/go/issues/31859
func init()  {
	testing.Init()
}

var _ = func() bool {
	fmt.Println("1")
	testing.Init()
	fmt.Println("2")
	fmt.Println(testing.Verbose())
	return true
}()



var defaults = Shop{
	Verbose: testing.Verbose(),
	//Verbose:      false,
	Cakes:        20,
	BakeTime:     10 * time.Millisecond,
	NumIcers:     1,
	IceTime:      10 * time.Millisecond,
	InscribeTime: 10 * time.Millisecond,
}

func Benchmark(b *testing.B) {
	cakeshop := defaults
	cakeshop.Work(b.N) // 224ms
}

func BenchmarkBuffers(b *testing.B) {
	cakeshop := defaults
	cakeshop.BakeBuf = 10
	cakeshop.IceBuf = 10
	cakeshop.Work(b.N)
}

func BenchmarkVariable(b *testing.B) {
	cakeshop := defaults
	cakeshop.BakeStdDev = cakeshop.BakeTime / 4
	cakeshop.IceStdDev = cakeshop.IceTime / 4
	cakeshop.InscribeStdDev = cakeshop.InscribeTime / 4
	cakeshop.Work(b.N)
}

func BenchmarkVariableBuffers(b *testing.B) {
	cakeshop := defaults
	cakeshop.BakeStdDev = cakeshop.BakeTime / 4
	cakeshop.IceStdDev = cakeshop.IceTime / 4
	cakeshop.InscribeStdDev = cakeshop.InscribeTime / 4
	cakeshop.BakeBuf = 10
	cakeshop.IceBuf = 10
	cakeshop.Work(b.N)
}

func BenchmarkSlowIcing(b *testing.B) {
	cakeshop := defaults
	cakeshop.IceTime = 50 * time.Millisecond
	cakeshop.Work(b.N)
}

func BenchmarkSlowIcingManyIcers(b *testing.B) {
	cakeshop := defaults
	cakeshop.IceTime = 50 * time.Millisecond
	cakeshop.NumIcers = 5
	cakeshop.Work(b.N)
}
