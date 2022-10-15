class Solution
{
public:
    // top-down approach (memoisation)

    int helper(TreeNode *root, unordered_map<TreeNode *, int> &mp)
    {
        if (!root)
            return 0;

        if (mp.find(root) != mp.end())
            return mp[root]; // check

        int include = root->val;
        if (root->left)
        {
            if (root->left->left)
                include += helper(root->left->left, mp);
            if (root->left->right)
                include += helper(root->left->right, mp);
        }
        if (root->right)
        {
            if (root->right->left)
                include += helper(root->right->left, mp);
            if (root->right->right)
                include += helper(root->right->right, mp);
        }
        int exclude = helper(root->left, mp) + helper(root->right, mp);

        mp[root] = max(include, exclude); // store
        return max(include, exclude);
    }
    int rob(TreeNode *root)
    {
        unordered_map<TreeNode *, int> mp;
        return helper(root, mp);
    }
};