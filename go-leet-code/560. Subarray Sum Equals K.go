package main

func subarraySum(nums []int, k int) int {
	hash := make(map[int32]int32, len(nums))
	ret := int32(0)
	hash[0] = 1
	cumulative := 0
	for _, value := range nums {
		cumulative += value
		count := hash[int32(cumulative-k)]
		ret += count

		hash[int32(cumulative)] += 1
	}
	return int(ret)
}
