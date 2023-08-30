class Solution {
public:
    void f(int n1, int n2, string s, vector<string> &ans){
        if(n1==0 && n2==0){
            ans.push_back(s);
            return;
        }
        if(n1){
            f(n1-1, n2, s + '(', ans);
        }
        if(n2>n1){
            f(n1, n2-1, s + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, n, "", ans);
        return ans;
    }
};