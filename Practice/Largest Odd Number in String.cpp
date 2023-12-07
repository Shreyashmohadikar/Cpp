class Solution {
public:
    string largestOddNumber(string num) {
        int i = num.size() - 1;
        string ans = ""; 
        while(i >= 0){
            if((num[i] - '0') % 2 != 0){
                for(int j=0; j<=i; j++){
                    ans += num[j];
                }
                break;
            }
            i--;
        }
        return ans;
    }
};