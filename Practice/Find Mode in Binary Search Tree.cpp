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
    void inorder(TreeNode *root, vector<int> &temp)
    {
        if (root == NULL)
            return;

        inorder(root->left, temp);
        temp.push_back(root->val);
        inorder(root->right, temp);
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> temp;
        inorder(root, temp);

        unordered_map<int, int> mp;
        for (auto it : temp)
        {
            mp[it]++;
        }
        int maxi = 0;
        for (auto it : mp)
        {
            maxi = max(maxi, it.second);
        }
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second == maxi)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};