//I re did this prompt because I missed the fact that the duplicates didnt need to be deleted
//So i made it so that duplicate values simply had other values shifted over them
//this is a good deal faster than the vector.erase() method
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        short j = 1, i = 1;
        if (nums.size() == 0) return 0;
        while (i < nums.size()) {
            if (nums[i-1] != nums[i]) nums[j++] = nums[i++];
            else i++;
        }
        return j;
    }
};
