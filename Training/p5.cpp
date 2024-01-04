#include<iostream>
#include<string>
using namespace std;

int main(){
    int hr, min;
    cin>>hr>>min;
    if(hr > 24){
        hr = 24 - hr;
    }
    else{
        hr = 23 - hr;
        min = 60 - min;
    }
    if(min == 60){
        hr++;
    }
    cout<<hr<<":"<<min;
    return 0;
}
//convert into min for both hr and min then evaluate**