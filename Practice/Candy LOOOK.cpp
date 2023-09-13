class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candyArr(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candyArr[i] = candyArr[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candyArr[i] = max(candyArr[i], candyArr[i + 1] + 1);
            }
        }
        int totalCandy = 0;
        for (int i = 0; i < n; i++)
        {
            totalCandy += candyArr[i];
        }
        return totalCandy;
    }
};