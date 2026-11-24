class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int t = 0;
        int a = 0;
        int m = nums[0];
        int b = 0;
        int n = nums[0];
        for(int num : nums){
            a = max(num, a + num);
            m = max(m, a);
            b = min(num, b + num);
            n = min(n, b);
            t += num;
        }
        if(m < 0){
            return m;
        }
        return max(m, t - n);
    }
};