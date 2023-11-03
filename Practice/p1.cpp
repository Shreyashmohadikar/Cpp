#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> arr) {
    int n = arr.size();
    if (n == 1) return arr[0];
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {  // Corrected condition for odd positions
            temp.push_back(arr[i]);
        }
    }
    return solve(temp);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    cout << solve(arr) << endl;
    return 0;
}
