//You are given the root of a binary tree, check whether the tree is symmetric around its center

/*
  Example :
    Input: root = [1,2,2,3,4,4,3]
    Output: true
*/

/*
  Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
*/

bool isMirror(struct TreeNode* ptr1,struct TreeNode* ptr2)
{
    if(!ptr1&&!ptr2)
        return true;
    if(!ptr1||!ptr2)
        return false;
    if(ptr1->val!=ptr2->val)
        return false;
    return isMirror(ptr1->left,ptr2->right)&&isMirror(ptr1->right,ptr2->left);
}
bool isSymmetric(struct TreeNode* root){
    if(!root)
        return true;
    return isMirror(root->left,root->right);
}
