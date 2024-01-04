#include<iostream>
#include<vector>
using namespace std;

int main(){
    int b, n;
    cin>>b>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i] = (arr[i] % 2) + (arr[i] / 2);
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    if(sum > b){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}