class Solution {
public:
    string count(string s){
        string ans = "";
        for(int i=0; i<s.size(); i++){
            int count = 1;
            while(s[i] == s[i+1]){
                i++;
                count++;
            }
            string countStr = to_string(count);
            ans += countStr;
            ans += s[i];
        }
        return ans;
    }

    string countAndSay(int n) {
        string ans = "1";
        if(n == 1){
            return ans;
        }
        for(int i=2; i<=n; i++){
            string t = count(ans);
            ans = t;
        }
        return ans;
    }
};