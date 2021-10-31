/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
*/

class Solution {
public:
    
    
    int helper(TreeNode*root, int &res)
    {
        if(root==NULL)
            return 0;
        int l=helper(root->left,res);
        int r=helper(root->right,res);
        
        if(l<0) 
            l=0;
        if(r<0)
            r=0;
        
        res=max(res, l+r+root->val);   //global maximum
        root->val+=max(l,r);    //max sum of subtree rooted here
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        int res=INT_MIN;
        helper(root,res);
        return res;
        
    }
};
