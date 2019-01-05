package main

import "fmt"
import "github.com/golang-collections/collections/stack"

func main() {
	fmt.Println("Hello, 世界")

	st := stack.New()
	st.Push(100)
	st.Push("olee")

	fmt.Println(st.Peek())
	st.Pop()
	fmt.Println(st.Peek())

}
