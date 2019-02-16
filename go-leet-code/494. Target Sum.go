package main

func findTargetSumWays(nums []int, S int) int {
	dp := make(map[int]map[int]int)
	var rec func(pos, sum int) int
	rec = func(pos, sum int) int {
		if pos >= len(nums) {
			if S == sum {
				return 1
			}
			return 0
		}
		ret := 0
		if ret, okay := dp[pos][sum]; okay == true {
			return ret
		}

		ret += rec(pos+1, sum+nums[pos])
		ret += rec(pos+1, sum-nums[pos])
		if dp[pos] == nil {
			dp[pos] = make(map[int]int)
		}
		dp[pos][sum] = ret
		return ret
	}
	return rec(0, 0)
}
