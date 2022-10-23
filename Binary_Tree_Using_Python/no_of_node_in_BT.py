
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

def findNodeCount(root):

	if root==None:

		return 0


	return  1 + findNodeCount(root.left) + findNodeCount(root.right)


print(findNodeCount(root))