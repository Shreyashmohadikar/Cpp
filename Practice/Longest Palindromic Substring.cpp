class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans;
        int maxLen = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalindrome(s, i, j) && j-i+1 > maxLen){
                    maxLen = j-i+1;
                    ans = s.substr(i, maxLen);
                }
            }
        }
        return ans;
    }
};