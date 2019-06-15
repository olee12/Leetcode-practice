package main

func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return head
	}
	dummy := &ListNode{}
	dummy.Next = head
	head = dummy
	prev := dummy
	curr := head.Next

	for curr != nil {
		flag := false
		for curr.Next != nil && curr.Val == curr.Next.Val {
			flag = true
			curr = curr.Next
		}
		if flag && curr != nil {
			curr = curr.Next

		} else {
			prev.Next = curr
			prev = prev.Next
			if prev != nil {
				curr = prev.Next
			}
		}

	}
	prev.Next = curr
	return head.Next

}
