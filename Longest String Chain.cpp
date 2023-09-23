class Solution
{
public:
    bool check(string &s, string &t)
    {
        if (s.size() != t.size() + 1)
        {
            return 0;
        }
        int i = 0, j = 0;
        while (j < t.size() && i < s.size())
        {
            if (s[i] == t[j])
            {
                j++;
                i++;
            }
            else
            {
                i++;
            }
        }
        return j == t.size();
    }
    int length(int i, int prev, vector<string> &arr, vector<vector<int>> &dp)
    {
        if (i >= arr.size())
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        int notpick = length(i + 1, prev, arr, dp);
        int pick = 0;
        if (prev == -1 || check(arr[i], arr[prev]))
        {
            pick = 1 + length(i + 1, i, arr, dp);
        }
        return dp[i][prev + 1] = max(pick, notpick);
    }

    static bool compute(string &s, string &t)
    {
        return (s.size() < t.size());
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), compute);
        vector<vector<int>> dp(words.size(), vector<int>(words.size() + 1, -1));
        return length(0, -1, words, dp);
    }
};


