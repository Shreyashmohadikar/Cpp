#include<bits/stdc++.h>
using namespace std;

int solve(int x, int y, int z){
    int ans = x;
    while(z--){
        if(x > y){
            x--;
        }
        else{
            x++;
        }
        ans = max(ans, x);
    }
    return ans;
}
int main(){
    int x, y, z;
    cin>>x>>y>>z;
    int ans = solve(x, y, z);
    cout<<ans<<endl;
    return 0;
}