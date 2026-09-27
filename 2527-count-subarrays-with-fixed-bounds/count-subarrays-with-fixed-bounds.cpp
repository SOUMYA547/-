class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastBad = -1;
        int lastMin = -1;
        int lastMax = -1;

        for(int i  = 0; i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                lastBad = i;
            }
            if(nums[i] == minK){
                lastMin = i;
            }
            if(nums[i] == maxK){
                lastMax = i;
            }
            int validStarts = min(lastMin, lastMax) - lastBad;

            if(validStarts > 0){
                ans += validStarts;
            }
        }
        return ans;

    }
};