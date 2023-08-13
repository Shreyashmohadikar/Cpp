class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> stk;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                
                int t=0, f=0;
                while(stk.top() == 't' || stk.top() == 'f'){
                    if(stk.top() == 't'){
                        t = 1;
                    }
                    if(stk.top() == 'f'){
                        f = 1;
                    }
                    stk.pop();
                }
                char temp = stk.top();
                stk.pop();

                if(temp == '&'){
                    if(f){
                        stk.push('f');
                    }
                    else{
                        stk.push('t');
                    }
                }

                else if(temp == '|'){
                    if(t){
                        stk.push('t');
                    }
                    else{
                        stk.push('f');
                    }
                }

                else if(temp == '!'){
                    if(t){
                        stk.push('f');
                    }
                    else{
                        stk.push('t');
                    }
                }

            }

            else if(s[i] != '(' && s[i] != ','){
                stk.push(s[i]);
            }
        }

        if(stk.top() == 't'){
            return true;
        }
        return false;
    }
};
