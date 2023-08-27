class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n = arr.size();
        int carry = 1;
        for(int i=n-1; i>=0; i--){
            int add = arr[i] + carry;
            arr[i] = add % 10;
            carry = add / 10;
        }
        if(carry > 0){
            arr.insert(arr.begin(), carry);
        }
        return arr;
    }
};