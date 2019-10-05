package problem

func sumEvenAfterQueries(A []int, queries [][]int) []int {
	total := 0
	for i := range A {
		if A[i]%2 == 0 {
			total += A[i]
		}
	}

	ret := make([]int, 0, len(A))
	for _, q := range queries {
		val, index := q[0], q[1]
		if (A[index]+val)%2 == 0 {
			if A[index]%2 != 0 {
				total += A[index]
			}
			A[index] += val
			total += val
		} else {
			if A[index]%2 == 0 {
				total -= A[index]
			}
			A[index] += val
		}
		// fmt.Println("Total: ",total)
		// fmt.Println("A: ",A)
		ret = append(ret, total)
	}
	return ret
}
