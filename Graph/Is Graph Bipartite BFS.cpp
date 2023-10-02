class Solution {
private:
  bool checkBFS(int start, int color[], vector<vector<int>> &graph){
      color[start] = 0;
      queue<int> q;
      q.push(start);
      while(!q.empty()){
          int node = q.front();
          q.pop();

          for(auto it : graph[node]){
              if(color[it] == -1){
                  q.push(it);
                  color[it] = !color[node];
              }
              else if(color[it] == color[node]){
                  return false;
              }
          }
      }
      return true;
  }
public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    int color[n];
    for(int i=0; i<n; i++){
      color[i] = -1;
    }    
    for(int i=0; i<n; i++){
        if(color[i] == -1){
            if(checkBFS(i, color, graph) == false){
                return false;
            }
        }
    }
    return true; 
  }
};