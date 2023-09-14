class Solution {
public:
    bool solve(int n, string start, vector<string> &ans, unordered_map<string, vector<string>> mp){
      if(ans.size() == n+1){
        return true;
      }
      if(mp[start].size() == 0){
        return false;
      }
      for(int i=0; i<mp[start].size(); i++){
        string temp = mp[start][i];
        ans.push_back(temp);
        mp[start].erase(mp[start].begin() + i);
        bool flag = solve(n, temp, ans, mp);
        
        if(flag){
          return true;
        }
        else
          mp[start].insert(mp[start].begin() + i, temp);
          ans.pop_back();{//backtracking
        }
      }
      return false;
    } 
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        sort(tickets.begin(), tickets.end());
        unordered_map<string, vector<string>> mp;

        for(int i=0; i<n; i++){
          mp[tickets[i][0]].push_back(tickets[i][1]);
        }
        vector<string> ans;
        ans.push_back("JFK");
        bool flag = solve(n, "JFK", ans, mp);
        return ans;
    }
};