class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        short i = nums.size() - 1;
        while (i > 0) {
            if (nums[i] == nums[i-1]) nums.erase(nums.begin() + (i - 1));
            i--;
        }
        return nums.size();
    }
};
