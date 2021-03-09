/**************************************************
	> File Name:  cake_test.go
	> Author:     Leuckart
	> Time:       2021-01-26 01:33
**************************************************/

// go test -v -bench=.
package cake

import (
	"testing"
	"time"
)

var defaults = Shop{
	Cakes:        20,
	BakeTime:     10 * time.Millisecond,
	NumIcers:     1,
	IceTime:      10 * time.Millisecond,
	InscribeTime: 10 * time.Millisecond,
}

func Benchmark(b *testing.B) {
	cakeshop := defaults
	cakeshop.Verbose = testing.Verbose()
	cakeshop.Work(b.N) // 224ms
}

func BenchmarkBuffers(b *testing.B) {
	cakeshop := defaults
	cakeshop.Verbose = testing.Verbose()
	cakeshop.BakeBuf = 10
	cakeshop.IceBuf = 10
	cakeshop.Work(b.N)
}

func BenchmarkVariable(b *testing.B) {
	cakeshop := defaults
	cakeshop.Verbose = testing.Verbose()
	cakeshop.BakeStdDev = cakeshop.BakeTime / 4
	cakeshop.IceStdDev = cakeshop.IceTime / 4
	cakeshop.InscribeStdDev = cakeshop.InscribeTime / 4
	cakeshop.Work(b.N)
}

func BenchmarkVariableBuffers(b *testing.B) {
	cakeshop := defaults
	cakeshop.Verbose = testing.Verbose()
	cakeshop.BakeStdDev = cakeshop.BakeTime / 4
	cakeshop.IceStdDev = cakeshop.IceTime / 4
	cakeshop.InscribeStdDev = cakeshop.InscribeTime / 4
	cakeshop.BakeBuf = 10
	cakeshop.IceBuf = 10
	cakeshop.Work(b.N)
}

func BenchmarkSlowIcing(b *testing.B) {
	cakeshop := defaults
	cakeshop.Verbose = testing.Verbose()
	cakeshop.IceTime = 50 * time.Millisecond
	cakeshop.Work(b.N)
}

func BenchmarkSlowIcingManyIcers(b *testing.B) {
	cakeshop := defaults
	cakeshop.Verbose = testing.Verbose()
	cakeshop.IceTime = 50 * time.Millisecond
	cakeshop.NumIcers = 5
	cakeshop.Work(b.N)
}
