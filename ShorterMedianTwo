class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int num1 = 0, num2 = 0; 
        short index1 = 0, index2 = 0;

        short median_loc = (nums1.size() + nums2.size()) / 2;

        for (int i = 0; i <= median_loc; i++){
            num2 = num1;
            if (index1 < nums1.size() & index2 < nums2.size()){
                if (nums1[index1] <= nums2[index2]) num1 = nums1[index1++];
                else num1 = nums2[index2++];
            }
            else if (index1 == nums1.size()){
                if (i != median_loc) num2 = nums2[index2 + (median_loc - i) - 1];
                num1 = nums2[index2 + (median_loc - i)];
                break;
            }
            else {
                if (i != median_loc) num2 = nums1[index1 + (median_loc - i) - 1];
                num1 = nums1[index1 + (median_loc - i)];
                break;
            }
        }
        if ((nums1.size() + nums2.size()) % 2 == 0) return (double)(num1 + num2) / 2;
        else return num1;
    }
};
