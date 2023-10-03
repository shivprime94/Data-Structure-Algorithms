class Node:

	def __init__(self,data):

		self.left = None
		self.right = None
		self.data = data



root = Node(1)
root.left = Node(0)

root.right = Node(1)

root.left.left = Node(0)
root.left.right = Node(1)

root.right.left = Node(0)
root.right.right = Node(0)

root.right.right.right = Node(0)
root.right.right.left = Node(0)



def SumOFRootToLeaf(root,string,ans):
	
	if root == None:
		return 

	if root.left == None and root.right == None:
		string += str(root.data)
		ans[0] += int(string,2)
		print(string,ans[0])


	string += str(root.data)
	
	if root.left !=  None:
		SumOFRootToLeaf(root.left,string,ans)

	if root.right != None:
		SumOFRootToLeaf(root.right,string,ans)

	return ans

ans = [0,]
string = ''

anss = SumOFRootToLeaf(root,string,ans)

print(anss)
