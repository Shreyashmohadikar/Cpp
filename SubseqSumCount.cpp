#include <bits/stdc++.h>
using namespace std;
int Calc(int idx, int arr[], int n, int s, int sum)
{
    if (idx == n)
    {
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }
    // take
    s += arr[idx];
    int l = Calc(idx + 1, arr, n, s, sum);
    // not take
    s -= arr[idx];
    int r = Calc(idx + 1, arr, n, s, sum);

    return l + r;
}
int main()
{
    int arr[] = {1, 1, 1, 2, 0, 1, 2, 2};
    int n = 8;
    int sum = 3;
    cout << Calc(0, arr, n, 0, sum);
}