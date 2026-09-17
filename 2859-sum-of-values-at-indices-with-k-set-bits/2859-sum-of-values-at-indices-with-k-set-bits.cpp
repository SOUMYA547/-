class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int a = nums.size();
        int b = 0;
        for(int i = 0; i < a; i++){
            if (__builtin_popcount(i) == k){
                b += nums[i];
            }
        }
        return b;
    }
};