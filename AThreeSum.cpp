#include <vector>
class ThreeSum {
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            
            vector<vector<int>> triplets;
            int target, low, high, temp;
            
            //if the list isnt long enough to produce a vector then turn an empty one
            if (nums.size() < 3){
                return {};
            }
            //sort the list of numbers
            sort(nums.begin(), nums.end());
            for (int i = 0; i <= nums.size() - 3; i++){
                low = i+1;
                high = nums.size() - 1;
                target = 0 - nums[i];
                while (low < high){
                    temp = nums[low] + nums[high];
                    if (temp == target){
                        triplets.insert(triplets.end(), {nums[i], nums[low], nums[high]});
                        if (nums[low] == nums[high]) break;
                        while(low<high){
                            if (nums[low] == nums[low+1]) low++;
                            else if (nums[high] == nums[high-1]) high--;
                            else break;   
                        }
                        low++;
                        high--;  
                    }
                    else if (temp < target) low++;
                    else high--;
                }
                if (nums[0] == nums[nums.size() - 1]) break;
                while (i < nums.size() - 2){
                    if (nums[i] == nums[i+1]) i++;
                    else break;
                }
            }
            return triplets;
        }
    };
};
