package main

func findRedundantDirectedConnection(edges [][]int) []int {
	var find_par func(par []int, u int) int
	find_par = func(par []int, u int) int {
		if par[u] == u {
			return u
		}
		par[u] = find_par(par, par[u])
		return par[u]
	}
	var case1 []int
	var case2 []int
	par := make([]int, len(edges)+1)

	for i := 1; i <= len(edges); i++ {
		par[i] = i
	}

	for indx, edge := range edges {
		u := edge[0]
		v := edge[1]

		pu := find_par(par, u)
		pv := find_par(par, v)

		if pu != pv {
			if pv != v {
				case1 = edges[indx]
			} else {
				par[pv] = pu
			}
		} else {
			case2 = edges[indx]
		}
	}

	if len(case1) == 0 {
		return case2
	}
	if len(case2) == 0 {
		return case1
	}
	// both are
	for _, edge := range edges {
		if edge[1] == case1[1] {
			return edge
		}
	}
	return nil
}
