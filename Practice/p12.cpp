#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int count_B(string str){
    int count = 0;
    for(char c: str){
        if(c == 'B') count++;
    }
    return count;
}

int solve(int n, string str){
    int B = count_B(str);
    int ans = B;
    int i = 0;
    bool flag = 0;
    int temp = 0;
    while(i < n){
        if(str[i] == 'B'){
            i++;
            flag = 1;
        }
        else if(flag == 1 && str[i] == 'A'){
            temp++;
            flag = 0;
            // skip all the consecutive A's after the first one
            while(i < n && str[i] == 'A'){
                i++;
            }
        }
        else{
            i++;
        }
    }
    return min(ans, temp);
}

int main(){
    int n;
    string str;
    cin >> n >> str;
    cout << solve(n, str) << endl;
    return 0;
}