#include <bits/stdc++.h>
using namespace std;
bool Calc(int idx, vector<int> &ds, int arr[], int n, int s, int sum)
{
    if (idx == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    // take
    ds.push_back(arr[idx]);
    s += arr[idx];
    if (Calc(idx + 1, ds, arr, n, s, sum) == true)
    {
        return true;
    }
    // not take
    s -= arr[idx];
    ds.pop_back();
    if (Calc(idx + 1, ds, arr, n, s, sum) == true)
    {
        return true;
    }
}
int main()
{
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    Calc(0, ds, arr, n, 0, sum);
}