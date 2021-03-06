package problem

import (
	"math/rand"
	"time"
)

type Solution struct {
	w     []int
	sum   []int
	total int
}

func (this *Solution) initialize() {
	if len(this.w) == 0 {
		return
	}
	this.sum[0] = this.w[0]
	for i := 1; i < len(this.w); i++ {
		this.sum[i] = this.sum[i-1] + this.w[i]
		this.total = this.sum[i]
	}
}

func Constructor(w []int) Solution {
	rand.Seed(time.Now().Unix())
	sol := Solution{w: w}
	return sol
}

func (this *Solution) PickIndex() int {
	return this.lowerBound()
}

func (this *Solution) lowerBound() int {
	if len(this.sum) == 0 {
		return 0
	}
	val := rand.Intn(this.total + 1)
	low := 0
	high := len(this.sum)

	for low <= high {
		mid := (low + high) / 2
		if this.sum[mid] >= val {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return low
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(w);
 * param_1 := obj.PickIndex();
 */
