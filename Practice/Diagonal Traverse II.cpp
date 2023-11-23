#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int row = nums.size();
        vector<vector<int>> arr;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                arr.push_back({i + j, j, nums[i][j]});
            }
        }

        sort(arr.begin(), arr.end());

        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            ans.push_back(arr[i][2]);
        }
        return ans;
    }
};


///////////////////////////////////

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<int> ans;

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                ans.push_back(nums[row][col]);

                if(((row + 1) < nums.size()) && col == 0) q.push({row + 1, 0});
                if((col + 1) < nums[row].size()) q.push({row, col + 1});
            }
        }
        return ans;
    }
};