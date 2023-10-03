class Node:

	def __init__(self,data):

		self.left = None
		self.right = None
		self.data = data



root = Node(10)
root.left = Node(20)

root.right = Node(25)

root.left.left = Node(30)
root.left.right = Node(40)

root.right.left = Node(35)
root.right.right = Node(33)

# root.left.right.left = Node(42)

def Depth(root):

	if root== None:
		return 0

	left = 1 +Depth(root.left)

	right = 1 + Depth(root.right)

	return max(left,right)

print(Depth(root))

