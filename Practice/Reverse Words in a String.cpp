class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> arr;
        string currStr = "";
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                currStr += s[i];
            }
            else if (!currStr.empty()) {
                arr.push_back(currStr);
                currStr.clear();
            }
        }
        if (!currStr.empty()) {
            arr.push_back(currStr);
        }
        currStr.clear();
        reverse(arr.begin(), arr.end());

        for(int i=0; i<arr.size(); i++){
            currStr += arr[i];
            if(i < arr.size() - 1){
                currStr += ' ';
            }
        }
        return currStr;
    }
};

