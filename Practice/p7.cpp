// Given a number 'N' (containing at most 10,000 digits), find the
// next greater number having the same digits.
// It is guaranteed that there exists a next greater number having
// the same digits as N.
// Example 1
// Input
// 3
// 182
// Output
// 218
// Explanation
// Using the same digit the number of permutations are:
// 1. 128
// 2. 218
// 3. 281
// 4. 812
// 5. 821
// The next greatest number for 182 is 218.

#include <iostream>
#include <algorithm>
using namespace std;

void nextGreaterNumber(string &num)
{
    int n = num.size();

    // Step 1: Find the rightmost digit smaller than the digit to its right
    int i = n - 2;
    while (i >= 0 && num[i] >= num[i + 1])
    {
        i--;
    }

    // Step 2: Find the smallest digit to the right of x that is larger than x
    int j = n - 1;
    while (num[j] <= num[i])
    {
        j--;
    }

    // Step 3: Swap x and y
    swap(num[i], num[j]);

    // Step 4: Reverse the digits to the right of x
    reverse(num.begin() + i + 1, num.end());
}

int main()
{
    int n;
    cin >> n;

    string num;
    cin >> num;

    nextGreaterNumber(num);

    cout << num;

    return 0;
}
