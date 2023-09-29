#include <bits/stdc++.h>
using namespace std;
void Calc(int idx, vector<int> &ds, int arr[], int n)
{
    if (idx == n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take
    ds.push_back(arr[idx]);
    Calc(idx + 1, ds, arr, n);
    // not take
    ds.pop_back();
    Calc(idx + 1, ds, arr, n);
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    Calc(0, ds, arr, n);
}