class Solution {
private:
    void solve(TreeNode* root, int low, int high, vector<int> &arr){
        if(root == NULL){
            return;
        }
        int num = root->val;
        if(num >= low && num <= high){
            arr.push_back(num);
        }
        solve(root->left, low, high, arr);
        solve(root->right, low, high, arr);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> arr;
        solve(root, low, high, arr);
        int sum = 0;
        for(int it : arr){
            sum += it;
        }
        return sum;
    }
};