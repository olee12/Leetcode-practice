package main

func uniqueLetterString(str string) int {
	// create the index array
	index := make([][]int, 26)
	for i := range index {
		index[i] = make([]int, 2)
	}
	for i := 0; i < 26; i++ {
		for j := 0; j < 2; j++ {
			index[i][j] = -1
		}
	}
	// end of creating index array

	N := len(str)
	ret := 0
	mod := 1000000007

	// |-----|-------|-------|

	for i := 0; i < N; i++ {
		c := (int)(str[i] - 'A')
		ret = ret + ((i-index[c][1])*(index[c][1]-index[c][0])%mod)%mod
		//fmt.Printf("%d %c %d %d [ %d %d %d]\n", i, str[i], index[c][1], index[c][0],i - index[c][1],(index[c][1] - index[c][0]),(i - index[c][1]) * (index[c][1] - index[c][0]));
		index[c][1], index[c][0] = i, index[c][1]
	}

	for c := 0; c < 26; c++ {

		ret = ret + ((N-index[c][1])*(index[c][1]-index[c][0])%mod)%mod
	}

	return ret

}
