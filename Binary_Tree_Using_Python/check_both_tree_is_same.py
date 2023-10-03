class Node:

	def __init__(self,data):

		self.data = data
		self.left = None
		self.right = None


root1 = Node(3)

root1.left = Node(5)

root1.right = Node(1)
root1.left.left = Node(6)
root1.left.left.right = Node(1)

root1.left.right = Node(2)
root1.left.right.left = Node(4)



root = Node(3)

root.left = Node(5)

root.right = Node(1)
root.left.left = Node(6)
root.left.left.right = Node(1)

root.left.right = Node(2)
root.left.right.left = Node(4)

def comapre_two_BT(root,root1):

	if root == None and root1 == None:

		return True

	if root.data != root1.data :
		return False

	return comapre_two_BT(root.left,root1.left) and comapre_two_BT(root.right,root1.right)

print(comapre_two_BT(root,root1))


