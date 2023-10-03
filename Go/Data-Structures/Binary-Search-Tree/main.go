package main

import "fmt"

type Node struct {
	Key   int
	Left  *Node
	Right *Node
}

func (n *Node) Insert(k int) {
	if n.Key < k {
		if n.Right == nil {
			n.Right = &Node{Key: k}
		} else {
			n.Right.Insert(k)
		}
	} else if n.Key > k {
		if n.Left == nil {
			n.Left = &Node{Key: k}
		} else {
			n.Left.Insert(k)
		}
	}
}

func (n *Node) Search(k int) bool {
	if n == nil {
		return false
	}

	if n.Key < k {
		return n.Right.Search(k)
	} else if n.Key > k {
		return n.Left.Search(k)
	}

	return true
}

func main() {
	tree := &Node{Key: 100}
	fmt.Println(tree)
	tree.Insert(51)
	tree.Insert(202)
	tree.Insert(18)
	tree.Insert(78)
	tree.Insert(152)
	tree.Insert(312)
	tree.Insert(8)
	tree.Insert(26)
	tree.Insert(90)
	tree.Insert(286)

	fmt.Println(tree.Search(78))
}