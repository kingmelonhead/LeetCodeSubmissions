class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        short j = nums.size() - 1, i = 0;
        while (i < nums.size() && j >= i){
            if (nums[i] == val) nums[i] = nums[j--];
            else i++;
        }
        return ++j;
    }
};
