class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int wins = 0;
        int currWinner = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] > currWinner){
                currWinner = arr[i];
                wins = 1;
            }
            else{
                wins++;
            }
            if(wins == k){
                return currWinner;
            }
        }
        return currWinner;
    }
};