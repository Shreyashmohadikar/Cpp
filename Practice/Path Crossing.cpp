class Solution {
public:
    bool isPathCrossing(string path) {
        int p = 0, q = 0;
        set<pair<int, int>> st;
        st.insert({0,0});
        for(int i=0; i<path.size(); i++){
            if(path[i] =='N'){
                q++;
            }
            else if(path[i] =='S'){
                q--;
            }
            else if(path[i] =='E'){
                p++;
            }
            else{
                p--;
            }
            if(st.count({p,q})){
                return true;
            }
            st.insert({p, q});
        }
        return false;
    }
};