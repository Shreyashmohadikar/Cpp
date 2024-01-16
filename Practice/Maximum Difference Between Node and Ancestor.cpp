/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int diff = 0;
    void solve(TreeNode *root, int minVal, int maxVal)
    {
        if (root == NULL)
            return;
        diff = max(diff,
                   max(abs(minVal - root->val),
                       abs(maxVal - root->val)));

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        solve(root->left, minVal, maxVal);
        solve(root->right, minVal, maxVal);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int minVal = root->val, maxVal = root->val;
        solve(root, minVal, maxVal);
        return diff;
    }
};