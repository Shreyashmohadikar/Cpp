// A man wants to do rock climbing and reach the top of a steep peak. There is N number of
// Convenient rocks on the mountain which the mountaineer can step onto to reach the
// peak a little easy, The initial posttion/rock on which the rock climber iS standing currently
// denoted as I. From each rock, the person can skip utmost X rocks The task here is to
// find the number of ways a can climb to reach the peak
// Example 1:
// Input:
// 6 -> Value of N
// 3 -> Value of I
// 2 -> Value of X

// output:
// 3

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(int n, int x, vector<int> &dp){
    if(n<0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int ans = 0;
    for(int i=1; i<=x; i++){
        ans += solve(n-i, x, dp);
    }
    return dp[n] = ans;
}
int main(){
    int N, I, X;
    cin>>N>>I>>X;
    vector<int> dp(N+1, -1);
    int ans = solve(N-I, X, dp);
    cout<<"No. of Ways: "<<ans;
    return 0;
}