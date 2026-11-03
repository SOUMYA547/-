class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = 0;
        int a = nums.size();
        for(int i = 0; i < a; i++){
            n += m - nums[i];
        }
        return n;
    }
};