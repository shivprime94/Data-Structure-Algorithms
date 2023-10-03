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


def Path_Sum(root,summ,path):

	if root == None:
		return

	if root.left == None and root.right == None:

		summ +=root.data
		path +=str(root.data)
		print(path,summ)

	# summ += root.data
	path += str(root.data) +">"

	Path_Sum(root.left,summ + root.data,path)

	Path_Sum(root.right,summ + root.data,path)
Path_Sum(root1,0,'')