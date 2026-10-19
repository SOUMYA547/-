class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int c = nums[0];
        int m = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            c = max(nums[i], c+ nums[i]);
            m = max(m, c);
        }
        return m;
    }
};