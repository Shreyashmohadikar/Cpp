#include<bits/stdc++.h>
using namespace std;

bool isMirror(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return (s == rev);
}

string findWinner(vector<string> names, int N) {
    int n = names.size();
    vector<string> temp;
    for(int i = 0; i < n; i++) {
        if(!isMirror(names[i])) {
            temp.push_back(names[i]);
        }
    }
    while(temp.size() > 1) {
        vector<string> temp2;
        for(int i = 0; i < temp.size(); i++) {
            if((i+1) % N != 0) {
                temp2.push_back(temp[i]);
            }
        }
        temp = temp2;
    }
    return temp[0];
}

int main() {
    vector<string> names = {"Janu", "gita", "sana", "gopi", "jaslin", "Tony", "Ritu", "Naina", "sonu", "Neha"};

    int N = 2;
    cout << findWinner(names, N) << endl;
    return 0;
}
