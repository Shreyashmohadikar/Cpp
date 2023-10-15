#include<bits/stdc++.h>
using namespace std;

int solve(int x, int y, int z){
    if(x > y){
        return x;
    }
    else if(x == y){
        return x + (z/2);
    }
    else{
        z = z - (y-x);
        return y + (z/2);
    }
}
int main(){
    int x, y, z;
    cin>>x>>y>>z;
    int ans = solve(x, y, z);
    cout<<ans<<endl;
    return 0;
}