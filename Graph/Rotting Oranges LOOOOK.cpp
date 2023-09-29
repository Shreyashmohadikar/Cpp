// using BFS trversal
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[m][n];
        queue<pair<pair<int, int>, int>> q;
        //{{row, col}, time}
        int cntFresh = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1){
                    cntFresh++;
                }

            }
        }
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int ans = 0;
        int cnt = 0;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans, t);
            q.pop();

            for(int i=0; i<4; i++){
                int newRow = r + drow[i];
                int newCol = c + dcol[i];

                if(newRow < m && newCol < n && newRow >= 0 && newCol >= 0
                    && grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0)
                    {
                        q.push({{newRow, newCol}, t+1});
                        vis[newRow][newCol] = 2;
                        cnt++;
                    }
            }
        }

        if(cnt != cntFresh){
            return -1;
        }
        return ans;
    }
};