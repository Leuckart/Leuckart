/**************************************************
	> File Name:  conv.go
	> Author:     Leuckart
	> Time:       2021-01-17 03:00
**************************************************/

package tempconv

func CToF(c Celsius) Fahrenheit {
	return Fahrenheit(c*9/5 + 32)
}

func FToC(f Fahrenheit) Celsius {
	return Celsius((f - 32) * 5 / 9)
}
