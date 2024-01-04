#include<iostream>
#include<algorithm>
using namespace std;
// int nCr(int n, int r){
//     if(r > n){
//         return 0;
//     }
//     if(r == 0 || r == n){
//         return 1;
//     }
//     return nCr(n-1, r-1) + nCr(n-1, r);
// }
int fact(int n){
    if(n == 0){
        return 1;
    }
    return n * fact(n-1);
}
int nCr(int n, int r){
    return fact(n) / (fact(n - r) * fact(r));
}

int main(){
    int n, m, p, e;
    cin>>n>>m>>p>>e;
    int ans = nCr(n, p) * nCr(m, e);
    cout<<"Ans: "<<ans;
    return 0;
}