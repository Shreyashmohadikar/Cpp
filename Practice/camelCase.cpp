#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "saveNext";
    string temp = "";
    for(int i=0; i<str.size(); i++){
        if(islower(str[i])){
            temp += toupper(str[i]) ;
        }
        else{
            cout<<temp<<endl;
            temp = "";
            temp += tolower(str[i]);
        }
    }
    cout<<temp<<endl;
    return 0;
}