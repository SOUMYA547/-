class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> a, b;
        for(int i = 0; i < n / 2; i++) a.push_back(nums[i]);
        for(int i = n / 2; i < n; i++) b.push_back(nums[i]);
        vector<long long> x, y;
        auto generate = [](vector<int>& v, vector<long long>& sums){
            sums = {0};
            for(int num : v){
                int size = sums.size();
                for(int i = 0; i < size; i++)
                sums.push_back(sums[i] + num);
    }
};
        generate(a, x);
        generate(b, y);
        sort(y.begin(), y.end());
        long long ans = abs((long long) goal);
        for(long long sum : x){
            long long need = goal - sum;
            auto it = lower_bound(y.begin(), y.end(), need);
            if(it != y.end())
                ans = min(ans, abs(sum + *it - goal));
            if(it != y.begin()){
            --it;
                ans = min(ans, abs(sum + *it - goal));
            }
        }
        return ans;
    }
};