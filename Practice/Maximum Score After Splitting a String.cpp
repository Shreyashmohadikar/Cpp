class Solution {
public:
    int maxScore(string s) {
        int numZeros = 0;
        int numOnes = count(s.begin(), s.end(), '1');
        int count = 0;
        for(int i=0; i<s.size()-1; i++){
            numZeros += (s[i] == '0');
            numOnes -= (s[i] == '1');
            count = max(count, numZeros + numOnes);
        }
        return count;
    }
};