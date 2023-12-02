class Solution {
private:
    bool check(string &temp, string &chars){
        int j=0;
        sort(temp.begin(), temp.end());
        for(int i=0; i<temp.size(); i++){
            while(temp[i] != chars[j] && j<chars.size()){
                j++;
            }
            if(j == chars.size()){
                return false;
            }
            j++;
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans = 0;
        sort(chars.begin(), chars.end());
        for(int i=0; i<words.size(); i++){
            string temp = words[i];
            if(check(temp, chars)){
                ans += temp.size();
            }
        }
        return ans;
    }
};
