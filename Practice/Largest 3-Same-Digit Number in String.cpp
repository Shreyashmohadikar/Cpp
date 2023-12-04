class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        for(int i=0; i<num.size()-2; i++){
            if(num[i+1] == num[i] && num[i+2] == num[i]){
                ans = max(ans, num[i] - '0');
                i += 2;
            }
        }
        if(ans == -1){
            return "";
        }
        string result(3, ans + '0');
        return result;
    }
};