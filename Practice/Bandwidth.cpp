#include<bits/stdc++.h>
using namespace std;
long long f(int i, vector<int> &bandwidth, vector<int> &request, int total_bandwidth, vector<vector<long long>> &dp){
    if(i == 0){
        if(bandwidth[i] <= total_bandwidth){
            return request[i];
        }
        else{
            return 0;
        }
    }
    if(dp[i][total_bandwidth] != -1){
        return dp[i][total_bandwidth];
    }
    int notTake = f(i-1, bandwidth, request, total_bandwidth, dp);
    int take = INT_MIN;
    if(bandwidth[i] <= total_bandwidth){
        take = request[i] + f(i-1, bandwidth, request, total_bandwidth - bandwidth[i], dp);
    }
    return dp[i][total_bandwidth] = max(take, notTake);
}
long getMaxRequests(vector<int> &bandwidth, vector<int> &request, int total_bandwidth){
    int n = bandwidth.size();
    vector<vector<long long>> dp(n, vector<long long>(total_bandwidth + 1, -1));
    return f(n-1, bandwidth, request, total_bandwidth, dp);
}
int main(){
    vector<int> bandwidth = {200, 100, 350, 50, 100};
    vector<int> request = {270, 142, 450, 124, 189};
    int total_bandwidth = 500;
    long long maxRequests = getMaxRequests(bandwidth, request, total_bandwidth);
    cout << "Maximum number of requests that can be served: " << maxRequests << endl;
    return 0;
}