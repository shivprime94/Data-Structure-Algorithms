class Node:

	def __init__(self,data):

		self.data = data
		self.left = None
		self.right = None


root1 = Node(3)

root1.left = Node(5)

root1.right = Node(1)
root1.left.left = Node(6)

root1.left.right = Node(2)
root1.left.right.left = Node(4)



def SumOf_left_leaf(root,left):

	if root == None:
		return 0

	if root.left == None and root.right == None and left :
		# print(root.data)

		return root.data

	l = SumOf_left_leaf(root.left,True)

	r = SumOf_left_leaf(root.right,False)

	return l+r

ans = []
print(SumOf_left_leaf(root1,False))

