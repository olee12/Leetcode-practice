package problem

func removeDuplicates(nums []int) int {
	index, i, next := 0, 0, 0

	for i < len(nums) {
		next, nums[index] = i, nums[i]
		index++
		for next < len(nums) && nums[i] == nums[next] {
			next++
		}
		if next-i > 2 {
			nums[index] = nums[i]
			index++
			i = next
		} else {
			i++
		}
	}
	return index
}
