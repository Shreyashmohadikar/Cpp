#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr = {{0,1}, {1,2}, {3,4}, {2,4}, {2,6}, {5,4}};
    int N = 7;
    int M = 6;
    int K = 5;

    unordered_map<int, int> mp;
    for(int i=0; i<M; i++){
        mp[arr[i][0]]++;
        mp[arr[i][1]]++;
    }

    int count = 0;
    for(int i=0; i<N; i++){
        if(mp[i] > 1){
            count++;
        }
    }

    int ans = count * K;
    cout<<endl<<"Cost: "<<ans<<endl;
    return 0;
}
