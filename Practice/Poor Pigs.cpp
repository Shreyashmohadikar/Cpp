class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int cycle = (minutesToTest / minutesToDie) + 1;
        for (int pig = 0; pig <= 7; pig++)
        {
            int currBucket = pow(cycle, pig);
            if (currBucket >= buckets)
            {
                return pig;
            }
        }
        return 7;
    }
};