class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s.size() == t.size()){
            int i=0, j=0;
            while(i<s.size() && j<t.size()){
                if(s[i] != t[j]){
                    return false;
                }
                i++;
                j++;
            }
            return true;
        }
        return false;
    }
};