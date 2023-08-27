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


/////

class Solution {
public:
    void sortColors(vector<int>& arr) {
        int c0 = 0, c1 = 0, c2 = 0;
        for(auto it : arr){
            if(it == 0){
                c0++;
            }
            if(it == 1){
                c1++;
            }
            if(it == 2){
                c2++;
            }
        }
        int i = 0;
        while(c0 != 0){
            arr[i] = 0;
            c0--;
            i++;
        }
        while(c1 != 0){
            arr[i] = 1;
            c1--;
            i++;
        }
        while(c2 != 0){
            arr[i] = 2;
            c2--;
            i++;
        }
        return;
    }
};
