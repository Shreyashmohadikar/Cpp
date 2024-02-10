class Solution {
private:
    bool isPalin(string &s, int i, int j){
        if(i==j) return true;
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};