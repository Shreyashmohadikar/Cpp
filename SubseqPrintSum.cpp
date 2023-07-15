#include <bits/stdc++.h>
using namespace std;
void Calc(int idx, vector<int> &ds, int arr[], int n, int s, int sum)
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
        }
        return;
    }
    // take
    ds.push_back(arr[idx]);
    s += arr[idx];
    Calc(idx + 1, ds, arr, n, s, sum);
    // not take
    s -= arr[idx];
    ds.pop_back();
    Calc(idx + 1, ds, arr, n, s, sum);
}
int main()
{
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    Calc(0, ds, arr, n, 0, sum);
}