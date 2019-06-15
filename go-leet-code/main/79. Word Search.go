package main

func exist(board [][]byte, word string) bool {
	var visited [][]bool
	var dfs func(i, j int, pos int) bool
	dfs = func(i, j int, pos int) bool {
		// fmt.Println(i, j, pos)
		if pos == len(word) {
			return true
		}
		// time.Sleep(50 * time.Millisecond)
		if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) {
			return false
		}

		if word[pos] != board[i][j] {
			return false
		}

		if visited[i][j] {
			return false
		}

		visited[i][j] = true
		flag := false
		flag = dfs(i+1, j, pos+1)
		if flag == false {
			flag = dfs(i, j+1, pos+1)
		}
		if flag == false {
			flag = dfs(i-1, j, pos+1)
		}
		if flag == false {
			flag = dfs(i, j-1, pos+1)
		}
		visited[i][j] = false
		return flag
	}
	visited = make([][]bool, len(board))
	for cj := 0; cj < len(board); cj++ {
		visited[cj] = make([]bool, len(board[0]))
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] == word[0] {

				if dfs(i, j, 0) {
					return true
				}
			}
		}
	}

	return false
}
