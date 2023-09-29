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
};

//////////////////////////////////////////////////////////

// Brute Force Approach
class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int maxArea = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            int minHeight = arr[i];
            for (int j = i; j < n; j++) {
                minHeight = min(minHeight, arr[j]);
                int width = j - i + 1;
                int area = minHeight * width;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
