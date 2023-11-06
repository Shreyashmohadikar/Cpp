#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    string str;
    while(n>0){
        str += (n%2) + '0';
        n /= 2;
    }
    reverse(str.begin(), str.end());
    for(int i=0; i<str.size()-1; i++){
        int dig = (str[i] - '0') ^ (str[i+1] - '0');
        str[i] = dig + '0';
    }

    int ans = 0;
    int pwr = 1;
    for(int i=str.size()-1; i>=0; i--){
        ans += (str[i] - '0') * pwr;
        pwr *= 2;
    }
    if(str[str.size()-1] == '0'){
        ans += 1;
    }
    cout<<ans;
    return 0;
}