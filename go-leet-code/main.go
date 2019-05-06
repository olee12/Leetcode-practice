package main

import "fmt"

func main() {
	head := &ListNode{Val: 1}
	node := head

	node.Next = &ListNode{Val: 1}
	node = node.Next
	node.Next = &ListNode{Val: 2}
	node = node.Next
	// fmt.Println("olee", node.Val)
	node.Next = &ListNode{Val: 3}
	node = node.Next
	node.Next = &ListNode{Val: 3}
	nHead := deleteDuplicates(head)
	// nHead := head
	for nHead != nil {
		fmt.Println(nHead.Val)
		nHead = nHead.Next
	}
}
