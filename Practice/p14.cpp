#include <iostream>
#include <string>
using namespace std;

int main() {
    int size = 10;
    string str = "ShreyashMohadikarVellloreInstisusdgfkfkjsbflkbaff";
    for(int i=0; i<str.size(); i++){
        if((i+1) > (size * size)){
            break;
        }
        cout<<str[i];
        if((i + 1) % size == 0 && (i + 1) < str.size()){
            cout<<endl;
        }
        else{
            cout<<" ";
        }
    }
    if(str.size())
    return 0;
}
