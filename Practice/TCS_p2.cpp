#include<bits/stdc++.h>
using namespace std;

int f(char c) {
    int ascii = int(c);
    int s = 0;
    while (ascii != 0) {
        s += ascii % 10;
        ascii /= 10;
    }
    if (s >= 10) {
        s = s % 10 + s / 10;
    }
    return s;
}

int main() {
    string c;
    cin >> c;
    int e;
    cin >> e;
    int v1 = f(c[0]);
    int v2 = f(c[1]);
    bool found = false;
    for (int i = e / v1; i >= 1; i--) {
        if ((e - i * v1) % v2 == 0 && (e - i * v1) / v2 != 0) {
            cout << c[0] << i << " " << c[1] << (e - i * v1) / v2 << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "Not Possible\n";
    }
    return 0;
}
