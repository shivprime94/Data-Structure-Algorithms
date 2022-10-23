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

root2 = Node(3)

root2.left= Node(5)
root2.right =Node(1)
root2.left.left = Node(6)

root2.right.left = Node(2)

root2.right.right = Node(1)

def Similar_left_tree(root,ans):

	if root ==None:
		return

	if root.left is None and root.right is None:
		ans.append(root.data)


	Similar_left_tree(root.left,ans)

	Similar_left_tree(root.right,ans)

	return ans

ans1 = []
print(Similar_left_tree(root1,ans1))
ans2 = []
print(Similar_left_tree(root2,ans2))






