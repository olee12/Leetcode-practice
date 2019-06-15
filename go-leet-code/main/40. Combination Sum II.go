package main

import (
	"sort"
)

func helperCombinationSum2(pos int, candidates []int, target int, sol []int, storage *([][]int)) {
	if target == 0 {
		//fmt.Printf("sol: %v\n",sol)
		//fmt.Printf("storage %v\n",storage)
		c := make([]int,len(sol))
		copy(c,sol)
		*storage = append(*storage, c)
		//fmt.Printf("after storage %v\n",storage)
		return
	} else if target < 0 {
		return
	}
	for i := pos; i < len(candidates); i++ {
		if i == pos || candidates[i] != candidates[i - 1] {
			sol = append(sol,candidates[i])
			helperCombinationSum2(i + 1, candidates, target - candidates[i], sol, storage)
			sol = sol[:len(sol)-1]
		}
	}
}

func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	ret := make([][]int, 0)
	sol := make([]int,0)
	helperCombinationSum2(0,candidates,target,sol,&ret)
	return ret
}
