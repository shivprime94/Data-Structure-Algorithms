class Solution {
public:
    int ans=0;
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root!=NULL)
        {
            if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
            {
                ans+=root->left->val;
            }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        }
        return ans;
    }
};
