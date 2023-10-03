package main

import "fmt"

type node struct {
	data int
	next *node
}

type linkedList struct {
	head   *node
	length int
}

func (l *linkedList) push(n *node) {
	second := l.head
	l.head = n
	l.head.next = second
	l.length++
}

func (l linkedList) printListData() {
	toPrint := l.head
	for l.length != 0 {
		fmt.Printf("%d ", toPrint.data)
		toPrint = toPrint.next
		l.length--
	}
	fmt.Printf("\n")
}

func (l *linkedList) pop(value int) {
	if l.length == 0 {
		return
	}

	if l.head.data == value {
		l.head = l.head.next
		l.length--
		return
	}

	previousToDelete := l.head
	for previousToDelete.next.data != value {
		if previousToDelete.next.next == nil {
			return
		}
		previousToDelete = previousToDelete.next
	}
	previousToDelete.next = previousToDelete.next.next
	l.length--
}

func main() {
	mylist := linkedList{}
	node1 := &node{data: 58}
	node2 := &node{data: 28}
	node3 := &node{data: 26}
	node4 := &node{data: 21}
	node5 := &node{data: 6}
	node6 := &node{data: 2}
	mylist.push(node1)
	mylist.push(node2)
	mylist.push(node3)
	mylist.push(node4)
	mylist.push(node5)
	mylist.push(node6)
	mylist.printListData()

	mylist.pop(100)
	mylist.pop(2)
	mylist.printListData()
	emptyList := linkedList{}
	emptyList.pop(10)
}
