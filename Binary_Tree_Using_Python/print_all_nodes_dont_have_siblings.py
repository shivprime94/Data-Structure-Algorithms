class Node:

	def __init__(self,data):

		self.data = data
		self.left = None
		self.right = None

        #   3
        #   /  \

        #  5    1
        #  / \
        # 6	  2	
        #  \  /
        #   1 4
            # /
           # 10


root1 = Node(3)

root1.left = Node(5)

root1.right = Node(1)
root1.left.left = Node(6)
root1.left.left.right = Node(1)

root1.left.right = Node(2)
root1.left.right.left = Node(4)

root1.left.right.left.left = Node(10)


def Dont_have_sib(root,res):

	if root == None:
		return

	if root.left == None and root.right == None:

		return

	if root.left != None and root.right != None:

		Dont_have_sib(root.left,res)
		Dont_have_sib(root.right,res)

	elif root.left != None :
		res.append(root.left.data)
		Dont_have_sib(root.left,res)

	elif root.right != None :

		res.append(root.right.data)
		Dont_have_sib(root.right,res)
	return 

res = []
Dont_have_sib(root1,res)

print(sorted(res))
