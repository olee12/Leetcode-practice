package main

const lim = 3005

var adj [][]int
var parent []int
var col, low, tim []int
var timer int
var groupID []int
var n, m, components int
var S Stack

type Stack interface {
	Init(int)
	Push(int)
	Pop()
	Top() int
	Size() int
	IsEmpty() bool
}

type stackImpl struct {
	s []int
}

func (st *stackImpl) Init(size int) {
	st.s = make([]int, size)
}

func (st *stackImpl) Push(elem int) {
	st.s = append(st.s, elem)
}
func (st *stackImpl) Pop() {
	st.s = st.s[:len(st.s)-1]
}
func (st *stackImpl) Top() int {
	return st.s[len(st.s)-1]
}
func (st *stackImpl) Size() int {
	return len(st.s)
}
func (st *stackImpl) IsEmpty() bool {
	return len(st.s) == 0
}

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func scc(u, par int) {
	col[u] = 1
	low[u] = timer
	tim[u] = timer
	timer++
	S.Push(u)
	// fmt.Println(u, par, len(adj[u]))
	for i := 0; i < len(adj[u]); i++ {
		v := adj[u][i]
		// fmt.Printf("v=%T\n", v)
		if v == par {
			continue
		}

		if col[v] == 1 {
			low[u] = Min(low[u], tim[v])
		} else if col[v] == 0 {
			scc(v, u)
			low[u] = Min(low[u], low[v])
		}
	}

	// SCC checking...
	if low[u] == tim[u] {
		// fmt.Println("component")
		tmp := -1
		for tmp != u {
			tmp = S.Top()
			S.Pop()
			groupID[tmp] = components
			col[tmp] = 2
			// fmt.Printf("%d ", tmp)
		}
		// fmt.Println()
		components++
	}

}
func findRedundantConnection(edges [][]int) []int {
	adj = make([][]int, lim)
	for i := 0; i < lim; i++ {
		adj[i] = make([]int, 0)
	}
	col, low, tim = make([]int, lim), make([]int, lim), make([]int, lim)
	timer = 0

	groupID = make([]int, lim)
	parent = make([]int, 0)

	n, m, components = 0, 0, 0

	S = &stackImpl{s: make([]int, 0)}

	for i := 0; i < len(edges); i++ {
		u := edges[i][0]
		v := edges[i][1]
		// fmt.Println("u,v", u, v)
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}
	scc(1, -1)

	// for i := 0; i < 6; i++ {
	// 	// fmt.Println(i, len(adj[i]))
	// 	fmt.Println(i, groupID[i])
	// }
	for i := len(edges) - 1; i >= 0; i-- {
		u := edges[i][0]
		v := edges[i][1]
		if groupID[u] == groupID[v] {
			return edges[i]
		}
	}
	return nil
}
