class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int l = 0;
        for(int num : st){
            if(st.find(num - 1) == st.end()){
                int n = num;
                int c = 1;
                while(st.find(n + 1) != st.end()){
                    n++;
                    c++;
                }
                l = max(l, c);
            }
        }
        return l;
    }
};