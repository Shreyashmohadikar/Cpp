class Solution {
public:
    vector<int> nextSmall(vector<int> &arr, int n){
        vector<int> ans(n);
        stack<int> stk;
        stk.push(n);
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(stk.top() != n && arr[stk.top()] >= curr){
                stk.pop();
            }
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }
    vector<int> prevSmall(vector<int> &arr, int n){
        vector<int> ans(n);
        stack<int> stk;
        stk.push(-1);
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(stk.top() != -1 && arr[stk.top()] >= curr){
                stk.pop();
            }
            ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int maxArea = INT_MIN;
        vector<int> prev = prevSmall(arr, n);
        vector<int> next = nextSmall(arr, n);
        for(int i=0; i<n; i++){
            int l = arr[i];
            int b = next[i] - prev[i] - 1;
            int area = l*b;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    arr[j]++;
                }
                else{
                    arr[j] = 0;
                }
            }
            int area = largestRectangleArea(arr);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
