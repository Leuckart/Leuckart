/**************************************************
	> File Name:  word.go
	> Author:     Leuckart
	> Time:       2021-01-28 03:15
**************************************************/

package word

func IsPalindrome(s string) bool {
	for i := range s {
		if s[i] != s[len(s)-i-1] {
			return false
		}
	}
	return true
}
