class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int i = 1;
        int currIdx = 0;

        while (i <= n && currIdx < target.size())
        {
            if (i == target[currIdx])
            {
                currIdx++;
                ans.push_back("Push");
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};