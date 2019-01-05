package main

import (
	"fmt"
)

func top(stack []int) int {
	return stack[len(stack)-1]
}
func pop(st []int) []int {
	st = st[:len(st)-1]
	return st

}
func largestRectangleArea(heights []int) int {
	mx, ret := 0, 0

	st := make([]int, 0)
	n := len(heights)
	for i := 0; i <= n; i++ {

		now := 0
		if i < n {
			now = heights[i]
		}

		for len(st) > 0 && heights[top(st)] > now {
			j := top(st)
			st = pop(st)
			k := -1
			if len(st) > 0 {
				k = top(st)
			}
			ret = (i - k - 1) * heights[j]
			if ret > mx {
				mx = ret
			}
			//fmt.Printf("i:%d j:%d k:%d ret:%d\n",i,j,k,ret)
		}
		st = append(st, i)
	}
	return mx
}

func main() {
	var arr = []int{2, 2, 2}
	fmt.Println(largestRectangleArea(arr))
}
