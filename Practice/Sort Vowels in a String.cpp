class Solution {
private:
    bool isVowelUpper(char c){
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        }
        return false;
    }
    bool isVowelLower(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
public:
    string sortVowels(string s) {
        string upStr = "";
        string lowStr = ""; 
        for(char it : s){
            if(isVowelUpper(it)){
                upStr += it;
            }
            else if(isVowelLower(it)){
                lowStr += it;
            }
        }
        sort(upStr.begin(), upStr.end());
        sort(lowStr.begin(), lowStr.end());
        string newStr = upStr + lowStr;
        string ans = "";
        int curr = 0;

        for(int i=0; i<s.size(); i++){
            if(isVowelLower(s[i]) || isVowelUpper(s[i])){
                ans += newStr[curr];
                curr++;
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};