#include <iostream>
using namespace std;

string findUniqueNumberBruteForce(const string& str, const string& pattern) {
    string uniqueNumber = "";
    int patternLength = pattern.length();

    for (int i = 0; i <= str.length() - patternLength; i++) {
        bool found = true;
        for (int j = 0; j < patternLength; j++) {
            if (pattern[j] != '#' && str[i+j] != '#' && pattern[j] != str[i + j]) {
                found = false;
                break;
            }
        }

        if (found) {
            uniqueNumber += to_string(i + 1); // Add 1 to convert index to 1-based
        }
    }

    return uniqueNumber.empty() ? "0" : uniqueNumber;
}

int main() {
    string str, pattern;
    cin >> str >> pattern;

    string uniqueNumber = findUniqueNumberBruteForce(str, pattern);
    cout << uniqueNumber << endl;

    return 0;
}
