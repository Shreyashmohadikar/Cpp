class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> stk1, stk2;
        for (char it : s)
        {
            if (it == '#' && !stk1.empty())
            {
                stk1.pop();
            }
            else if (it != '#')
            {
                stk1.push(it);
            }
        }
        for (char it : t)
        {
            if (it == '#' && !stk2.empty())
            {
                stk2.pop();
            }
            else if (it != '#')
            {
                stk2.push(it);
            }
        }

        while (!stk1.empty() && !stk2.empty())
        {
            if (stk1.top() != stk2.top())
            {
                return false;
            }
            stk1.pop();
            stk2.pop();
        }
        return stk1.empty() && stk2.empty();
    }
};