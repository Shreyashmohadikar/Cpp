class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lvlSize = q.size();
            int maxVal = INT_MIN;
            for(int i=0; i<lvlSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                maxVal = max(maxVal, curr->val);

                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};