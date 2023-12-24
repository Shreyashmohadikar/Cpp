class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : points){
            pq.push(it[0]);
        }
        int ans = 0;
        int temp = pq.top();
        pq.pop();
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            ans = max(ans, curr - temp);
            temp = curr;
        }
        return ans;
    }
};
