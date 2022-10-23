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


def check_target(root,cur_sum,target_sum):

	if root == None :

		return False

	if root.left == None and root.right == None:

		cur_sum += root.data

		return cur_sum == target_sum

	cur_sum +=root.data

	return check_target(root.left,cur_sum,target_sum) or check_target(root.right,cur_sum,target_sum)

cur_sum = 0

target_sum = 14
print(check_target(root1,cur_sum,target_sum))

