class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        for(char it : s){
            mp[it]++;
        }

        unordered_set<int> st;
        priority_queue<int> pq;
        int deletions = 0;

        for(auto it : mp){
            pq.push(it.second);
        }
        while(!pq.empty()){
            int currFreq = pq.top();
            pq.pop();

            while(currFreq > 0 && st.count(currFreq)){
                deletions++;
                currFreq--;
            }
            st.insert(currFreq);
        }
        return deletions;
    }
};