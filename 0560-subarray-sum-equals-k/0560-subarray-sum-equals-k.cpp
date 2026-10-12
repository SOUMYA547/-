class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int s = 0;
        int c = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            s += nums[i];
            int r = s - k;
            if(mp.find(r) != mp.end()){
                c += mp[r];
            }
            mp[s]++;
        }
        return c;
    }
};