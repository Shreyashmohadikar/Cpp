// Iterative

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return false;
        while (n % 4 == 0)
        {
            n /= 4;
        }
        return n == 1;
    }
};

// Recursive

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n == 0)
        {
            return false;
        }
        return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};