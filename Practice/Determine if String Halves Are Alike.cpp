class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vowelCount = 0;
        int mid = s.size() / 2;
        for(int i = 0; i < mid; i++){
            char charA = s[i];
            if(st.count(charA)) vowelCount++;

            char charB = s[mid + i];
            if(st.count(charB)) vowelCount--;
        }
        return vowelCount == 0;
    }
};