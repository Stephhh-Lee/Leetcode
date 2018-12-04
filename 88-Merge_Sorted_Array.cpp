class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=m+n-1,i,j;
        for(i= m-1, j=n-1; i>=0&&j>=0;){
            if(nums1[i]>nums2[j]){nums1[l]=nums1[i]; l--;i--;}
            else {nums1[l]=nums2[j]; l--;j--;}
        }
        if(i<0){
            for(i=0;i<=j;i++){
                nums1[i]=nums2[i];
            }
        }
    }
};
