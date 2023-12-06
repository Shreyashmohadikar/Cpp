class Solution {
public:
    int totalMoney(int n) {
        int amt = 0, monday = 1;
        int origMon = monday;
        for(int i = 0; i < n; i++){
            if(i % 7 == 0 && i > 0){
                monday = origMon + 1;
                origMon = monday;
            }
            amt += (monday + (i % 7));
        }
        return amt;
    }
};