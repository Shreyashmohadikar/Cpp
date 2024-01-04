#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    cin>>str;
    string ans = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'E' && str[i+1] == 'F'){
            i++;
        }
        else if(str[i] == 'G'){
            continue;
        }
        else{
            ans += str[i];
        }
    }
    cout<<ans;
}