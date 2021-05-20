#include<iostream>
#include <vector>
class MedianSortedArray{
    class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
            int size1 = nums1.size();
            int size2 = nums2.size();
            int size_total = size1 + size2;
            int temp1 = 0;
            int temp2 = 0;
            int index1 = 0;
            int index2 = 0;
            
            if(size1 == 0){
                if (size2 == 1) return nums2[0];
                else {
                    //find median of nums2 normally
                    index2 = size2/2;
                    if (size2 % 2 != 0) return nums2[index2]; // if odd
                    else return (double)(nums2[index2] + nums2[index2 - 1]) / 2; // if even
                }
            }
            if (size2 == 0){
                if (size1 == 1) return nums1[0];
                else { //find median of nums1 normally
                    index1 = size1/2;
                    if (size1 % 2 != 0) return nums1[index1]; //if odd
                    else return (double)(nums1[index1] + nums1[index1 - 1]) / 2; //if even
                    
                }
            }
            //find the median of them merged
            if (size_total % 2 == 0){ //if even
                size_total = size_total / 2;
                for (int i = 0; i < size_total ; i++){
                    if (index1 <= size1 - 1){
                        if (index2 <= size2 - 1){ //havent hit the end of either nums1 or nums2
                            if (nums1[index1] <= nums2[index2]){ //if next number from nums1 should go next
                                temp1 = nums1[index1];
                                index1++;
                                if (index1 == size1) temp2 = nums2[index2]; //if the end of nums1 is hit then set the next number to the next number from nums2
                                else {
                                    if (nums1[index1] <= nums2[index2]) temp2 = nums1[index1];
                                    else temp2 = nums2[index2];
                                }
                            }
                            else { //if next number from nums2 would be next
                                temp1 = nums2[index2];
                                index2++;
                                if (index2 == size2) temp2 = nums1[index1];
                                else {
                                    if (nums2[index2] <= nums1[index1]) temp2 = nums2[index2];
                                    else temp2 = nums1[index1];
                                }
                            }
                        }
                        else { //hit end of nums2 
                            if (i == size_total - 1){ //if at final stop in the main loop
                            if (index2 == size2 - 1){ // index2 is still in bounds
                                if (nums2[index2] <= nums1[index1]) return (double)(temp1 + nums2[index2]) / 2;
                                else return (double)(temp1 + nums1[index1]) / 2;
                            }
                            else return (double)(nums1[index1 + 1] + nums1[index1]) / 2;
                            }
                            else {
                                index1 += size_total - i;
                                return (double)(nums1[index1] + nums1[index1 - 1]) / 2;
                            }
                        }
                    }
                    else {
                        //hit the end of nums1
                        if (i == size_total - 1){
                            if (index1 == size1 - 1){
                                if (nums1[index1] <= nums2[index2]) return (double)(temp1 + nums1[index1]) / 2;
                                else return (double)(temp1 + nums2[index2]) / 2;
                            }
                            else return (double)(nums2[index2 + 1] + nums2[index2]) / 2;
                        }
                        else {
                            index2 += size_total - i;
                            return (double)(nums2[index2] + nums2[index2 - 1]) / 2;
                        }
                    }
                }
                return (double)(temp1 + temp2) / 2;
            }
            else { //if odd
                size_total = (size_total - 1) / 2;
                size_total++;
                for (int i = 0; i< size_total; i++){
                    if (index1 <= size1 - 1){
                        if (index2 <= size2 - 1){
                            if (nums1[index1]<= nums2[index2]){
                                temp1 = nums1[index1];
                                index1++;
                            }
                            else {
                                temp1 = nums2[index2];
                                index2++;
                            }
                        }
                        else {//hit end of nums2
                            if (i == size_total - 1){
                                if (index2 == size2 - 1){
                                    if (nums2[index2] <= nums1[index1]) return nums2[index2];
                                    else return nums1[index1];                       
                                }
                                else return nums1[index1];    
                            }
                            else return nums1[index1 + size_total -i - 1];
                        }
                    }
                    else { //hit end of nums1
                        if (i == size_total - 1){
                            if (index1 == size1 - 1){
                                if (nums1[index1] <= nums2[index2]) return nums1[index1];
                                else return nums2[index2];
                            }
                            else return nums2[index2];
                        }
                        else return nums2[index2 + size_total -i - 1];
                    }
                }
                return temp1;
            }
            
        }
    };
};