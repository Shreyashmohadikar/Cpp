// Min Cost to Connect All Points

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int mincost = 0;
        vector<bool> vis(n, false);

        while(n){
            auto next = pq.top();
            pq.pop();
            if(vis[next.second]){
                continue;
            }
            else{
                mincost += next.first;
                vis[next.second] = true;
                n--;
            }
            for(int i=0; i<points.size(); i++){
                if(!vis[i]) {
                    pq.push({abs(points[next.second][0] - points[i][0]) + 
                                abs(points[next.second][1] - points[i][1]), i});
                }
            }
        }
        return mincost;
    }
};