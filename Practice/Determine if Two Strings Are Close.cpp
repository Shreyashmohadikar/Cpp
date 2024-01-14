class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        if (n != m)
            return false;

        unordered_map<char, int> mp1, mp2;

        for (char &c : word1)
        {
            mp1[c]++;
        }
        for (char &c : word2)
        {
            mp2[c]++;
        }

        vector<char> arr, brr;
        vector<int> arr1, brr1;

        for (auto &it : mp1)
        {
            arr.push_back(it.first);
            arr1.push_back(it.second);
        }
        for (auto &it : mp2)
        {
            brr.push_back(it.first);
            brr1.push_back(it.second);
        }

        sort(arr.begin(), arr.end());
        sort(arr1.begin(), arr1.end());
        sort(brr.begin(), brr.end());
        sort(brr1.begin(), brr1.end());

        return (arr == brr && arr1 == brr1);
    }
};