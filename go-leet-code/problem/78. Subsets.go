package problem

func subsets(nums []int) [][]int {
	ret := make([][]int, 0)
	var rec func(int, []int)
	rec = func(pos int, inter []int) {
		// fmt.Printf("%v %v\n", pos, inter)
		if pos == len(nums) {
			tmp := make([]int, len(inter))
			copy(tmp, inter)
			ret = append(ret, tmp)
			return
		}
		rec(pos+1, inter)
		inter = append(inter, nums[pos])
		rec(pos+1, inter)
		inter = inter[:len(inter)-1]
	}

	masking := func() [][]int {
		mask := (1 << uint(len(nums))) - 1
		for mask >= 0 {
			set := make([]int, 0)
			for i := 0; i < len(nums); i++ {
				if ((mask >> uint(i)) & 0x1) != 0 {
					set = append(set, nums[i])
				}
			}
			ret = append(ret, set)
			mask--
		}
		return ret
	}

	if len(nums)%2 == 1 {
		inter := make([]int, 0)
		rec(0, inter)
		return ret
	}
	return masking()

}
