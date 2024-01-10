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
    void constructGraph(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->left)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        constructGraph(root->left);
        constructGraph(root->right);
    }

public:
    unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode *root, int start)
    {
        constructGraph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> vis;
        int ans = -1;

        while (!q.empty())
        {
            ans++;
            for (int levelSize = q.size(); levelSize > 0; levelSize--)
            {
                int currNode = q.front();
                q.pop();
                vis.insert(currNode);
                for (int it : graph[currNode])
                {
                    if (vis.count(it) == 0)
                    {
                        q.push(it);
                    }
                }
            }
        }
        return ans;
    }
};