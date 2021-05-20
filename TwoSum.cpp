#include <vector>
#include <map>
class TwoSum {
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> integer_map;
            int to_find;
            for (int i = 0; ; i++){
                to_find = target - nums[i]; // the number that is to be looked for 
                if (integer_map.find(to_find) != integer_map.end()) return {i, integer_map[to_find]}; //number was found
                integer_map[nums[i]] = i; // number wasnt found
            }
            return {};
        }
    };
}