class Solution
{
private:
    int f(int n, char endVowel, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp[n][endVowel - 'a'] != -1)
        {
            return dp[n][endVowel - 'a'];
        }

        long long count = 0;
        if (endVowel == 'a')
        {
            count = (count + f(n - 1, 'e', dp)) % MOD;
        }
        else if (endVowel == 'e')
        {
            count = (count + f(n - 1, 'a', dp)) % MOD;
            count = (count + f(n - 1, 'i', dp)) % MOD;
        }
        else if (endVowel == 'i')
        {
            count = (count + f(n - 1, 'a', dp)) % MOD;
            count = (count + f(n - 1, 'e', dp)) % MOD;
            count = (count + f(n - 1, 'o', dp)) % MOD;
            count = (count + f(n - 1, 'u', dp)) % MOD;
        }
        else if (endVowel == 'o')
        {
            count = (count + f(n - 1, 'i', dp)) % MOD;
            count = (count + f(n - 1, 'u', dp)) % MOD;
        }
        else
        {
            count = (count + f(n - 1, 'a', dp)) % MOD;
        }
        return dp[n][endVowel - 'a'] = (int)count;
    }

public:
    const int MOD = 1e9 + 7;
    int countVowelPermutation(int n)
    {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(26, -1));
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for (char &it : vowels)
        {
            ans = (ans + f(n - 1, it, dp)) % MOD;
        }
        return ans;
    }
};