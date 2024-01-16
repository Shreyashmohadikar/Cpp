class RandomizedSet {
private:
    unordered_set<int> st;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.count(val)){
            return 0;
        }
        else{
            st.insert(val);
            return 1;
        }
    }
    
    bool remove(int val) {
        if(st.count(val)){
            st.erase(val);
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int getRandom() {
        int idx = rand() % st.size();
        return *next(st.begin(), idx);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */