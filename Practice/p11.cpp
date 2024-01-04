#include <iostream>
#include <stack>
using namespace std;

void printMinimumNumber(string pattern) {
    stack<int> s;
    for (int i = 0; i <= pattern.size(); i++) {
        s.push(i + 1);
        if (i == pattern.size() || pattern[i] == 'I') {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
        }
    }
}

int main() {
    string pattern;
    cin >> pattern;
    printMinimumNumber(pattern);
    return 0;
}
