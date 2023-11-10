class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjMap;

        // Construct an adjacency list
        for (auto& pair : adjacentPairs) {
            adjMap[pair[0]].push_back(pair[1]);
            adjMap[pair[1]].push_back(pair[0]);
        }

        int n = adjMap.size();
        vector<int> result;

        // Find the starting point
        int start;
        for (auto& entry : adjMap) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }

        // Reconstruct the array using iterative DFS
        stack<int> stk;
        unordered_set<int> visited;

        stk.push(start);
        visited.insert(start);

        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            result.push_back(node);

            for (auto& neighbor : adjMap[node]) {
                if (visited.count(neighbor) == 0) {
                    stk.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return result;
    }
};
