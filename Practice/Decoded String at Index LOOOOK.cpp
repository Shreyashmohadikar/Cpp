class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long decodeSize = 0;
        for(char ch : s){
            if(isdigit(ch)){
                int digit = ch - '0';
                decodeSize *= digit;
            }
            else{
                decodeSize++;
            }
        }
        for(int i=s.size()-1; i>=0; i--){
            char currChar = s[i];
            if(isdigit(currChar)){
                int digit = currChar - '0';
                decodeSize /= digit;
                k %= decodeSize;
            }
            else{
                if(k == 0 || k == decodeSize){
                    return string(1, currChar);
                }
                decodeSize--;
            }
        }
        return "";
    }
};