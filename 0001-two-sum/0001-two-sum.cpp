#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // To store the number and its index
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // Calculate the complement
            if (num_map.find(complement) != num_map.end()) { // Check if complement exists in the map
                return {num_map[complement], i}; // Return the indices of the complement and current number
            }
            num_map[nums[i]] = i; // Store the index of the current number
        }
        return {}; // Should never reach here as per the problem's constraints
    }
};
