class Solution {
private:
    bool isPalin(string str){
        string temp = str;
        reverse(temp.begin(), temp.end());
        return str == temp;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& it : words) {
            if (isPalin(it)) {
                return it;
            }
        }
        return "";
    }
};