#include <iostream>
#include <vector>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> lis(n, 1); // Longest Increasing Subsequence ending at index i
    vector<int> lds(n, 1); // Longest Decreasing Subsequence starting from index i

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (arr[i] > arr[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int maxBitonicLength = 0;
    for (int i = 0; i < n; ++i) {
        maxBitonicLength = max(maxBitonicLength, lis[i] + lds[i] - 1);
    }

    return maxBitonicLength;
}

int main() {
    vector<int> arr = {1, 3, 5, 3, 21, 1, 2, 3, 4};
    int result = longestBitonicSubsequence(arr);
    cout << "Length of the longest bitonic subsequence: " << result << endl;

    return 0;
}
