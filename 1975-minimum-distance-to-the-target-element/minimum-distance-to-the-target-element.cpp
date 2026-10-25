class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int a = INT_MAX;
        int b = nums.size();
        for(int i = 0; i < b; i++){
            if(nums[i] == target){
                a = min(a, abs(i - start));
            }
        }
        return a;
    }
};