#include<iostream>
#include<string>
using namespace std;

int getAlphabetValue(char c) {
    if (c == 'A') return 0;
    if (c == 'B') return 1;

    // Calculate values for letters C and above
    int a = 0, b = 1, result = 0;
    for (char i = 'C'; i <= c; i++) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int calculateWordSum(const string& word) {
    int sum = 0;
    for (char c : word) {
        sum += getAlphabetValue(c);
    }
    return sum;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    int result = calculateWordSum(word);

    cout << "Sum of the alphabets in the word: " << result << endl;

    return 0;
}
