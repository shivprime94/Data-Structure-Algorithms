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



def LeftView_Of_Bt(root,level,set_level,left_view_nodes):


	if root ==None :

		return

	# if root.left == None and root,right :
	if level not in set_level:
		set_level.add(level)
		left_view_nodes.append(root.data)
		print(root.data)

	LeftView_Of_Bt(root.right,level+1,set_level,left_view_nodes)

	LeftView_Of_Bt(root.left,level +1,set_level,left_view_nodes)

	return left_view_nodes

print(LeftView_Of_Bt(root1,1,set(),[]))


