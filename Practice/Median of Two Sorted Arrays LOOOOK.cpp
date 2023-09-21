class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        int i=0, j=0, k=0;
        vector<int> merged(totalSize);

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                merged[k++] = nums1[i++];
            }
            else{
                merged[k++] = nums2[j++];
            }
        }
        while(i<nums1.size()){
            merged[k++] = nums1[i++];
        }
        while(j<nums2.size()){
            merged[k++] = nums2[j++];
        }

        int mSize = merged.size();
        if(mSize % 2 == 1){
            return merged[mSize / 2];
        }
        else{
            return (merged[mSize / 2] + merged[(mSize / 2) - 1]) / 2.0;
        }
    }
};