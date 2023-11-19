#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int INF = 1e9+7;

int findMinSets(string &s, int i, int num, int Y, vector<vector<int>> &memo) {
    if (num > Y) return INF;
    if (i == s.size()) return 0;
    if (memo[i][num] != -1) return memo[i][num];
    int option1 = 1 + findMinSets(s, i + 1, num * 10 + (s[i] - '0'), Y, memo);
    int option2 = 1 + findMinSets(s, i + 1, s[i] - '0', Y, memo);
    return memo[i][num] = min(option1, option2);
}

int main() {
    string s;
    int Y;
    cout << "Enter the string of digits on chairs: ";
    cin >> s;

    // Input validation to ensure the string contains only digits
    for (char c : s) {
        if (!isdigit(c)) {
            cout << "Invalid input: String should contain only digits." << endl;
            return 1;
        }
    }

    cout << "Enter the value of Y: ";
    cin >> Y;

    vector<vector<int>> memo(s.size(), vector<int>(Y + 1, -1));
    cout << "Output: " << findMinSets(s, 0, 0, Y, memo) << endl;

    return 0;
}
