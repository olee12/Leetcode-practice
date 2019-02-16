package main

func numsSameConsecDiff(N int, K int) []int {
	var rec func(int, int, int)
	ret := make([]int, 0)
	rec = func(pos, prv, now int) {
		if pos == 0 {
			ret = append(ret, now)
			return
		}
		if prv-K >= 0 {
			rec(pos-1, prv-K, now*10+(prv-K))
		}
		if prv+K <= 9 && K != 0 {
			rec(pos-1, prv+K, now*10+(prv+K))
		}
	}
	if N == 1 {
		ret = append(ret, 0)
	}
	for i := 1; i <= 9; i++ {
		rec(N-1, i, i)
	}
	return ret
}
