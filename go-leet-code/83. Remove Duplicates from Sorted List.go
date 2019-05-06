package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates83(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	prev := head
	curr := prev.Next

	for curr != nil {
		for curr != nil && curr.Val == prev.Val {
			curr = curr.Next
		}
		prev.Next = curr
		prev = prev.Next
		if prev != nil {
			curr = prev.Next
		}

	}
	return head
}
