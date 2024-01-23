class Solution
{
private:
    int solve(int idx, vector<string> &arr, string temp)
    {
        if (idx >= arr.size())
        {
            return temp.size();
        }

        string curr = temp;
        curr += arr[idx];

        unordered_set<char> st;
        for (char &c : curr)
            st.insert(c);

        if (st.size() == curr.size())
        {
            int take = solve(idx + 1, arr, curr);
            int notTake = solve(idx + 1, arr, temp);
            return max(take, notTake);
        }
        return solve(idx + 1, arr, temp);
    }

public:
    int maxLength(vector<string> &arr)
    {
        string temp = "";
        return solve(0, arr, temp);
    }
};