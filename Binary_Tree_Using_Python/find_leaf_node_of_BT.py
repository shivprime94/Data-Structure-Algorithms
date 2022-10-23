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

root.right.right.right = Node(46)

# Sum of leaf nodes 
print(root.right.right.right.data)

def countLeafNode(root,ans):

	if root == None:
		return 

	if root.left == None and root.right == None:

		ans[0] += root.data
		print(root.data,ans[0])

		return

	countLeafNode(root.left,ans)

	countLeafNode(root.right,ans)

	return ans[0]

var = [0,]
ans = countLeafNode(root,var)

print(ans)