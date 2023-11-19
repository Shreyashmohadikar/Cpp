#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Input the original marks for each question
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // Sort the array in ascending order
    sort(arr.begin(), arr.end());
    
    stack<int> stk;
    
    // Push the first element onto the stack
    stk.push(arr[0]);
    
    // Iterate through the array and adjust marks using the stack
    for(int i = 1; i < n; i++){
        if(stk.top() >= arr[i]){
            stk.push(stk.top() + 1);
        }
        else{
            stk.push(arr[i]);
        }
    }
    
    int ans = 0;
    
    // Calculate the minimum total marks
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }
    
    cout << ans;
    
    return 0;
}
