class Solution {
public:
    void sortColors(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : arr){
            pq.push(it);
        }
        arr.clear();
        while(!pq.empty()){
            arr.push_back(pq.top());
            pq.pop();
        }
        return;
    }
};
