#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    // cout<<str<<endl<<str.size()<<endl;
    string ans = "";
    for(int i=0; i<str.size(); i++){
        if(str[i] == '_'){
            ans += ' ';
            i++;
        }
        else if(str[i] == '#'){
            i+=2;
            while(i < str.size() && str[i] != ' '){
                ans += str[i];
                i++;
            }
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            if(i+1 == str.size() || str[i+1] == ' '){
                ans += (str[i] - '0') - 1 + 'A';
                i++;
            }//changes
            else if(str[i+1] >= '0' && str[i+1] <= '9'){
                ans += ((str[i] - '0' ) * 10 + (str[i+1] - '0' )) - 1 + 'A';
                i+=2;
            }
        }
        else{
            ans += str[i];
            i++;
        }
    }
    if(ans.size() == 0){
        cout<<"NULL";
    }
    else{
        cout<<ans;
    }
    return 0;
}