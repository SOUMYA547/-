class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
vector<vector<int>> dp(n, vector<int>(m, -1e9));

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                int take = nums1[i] * nums2[j];
                if(i > 0 && j > 0){
                    take += max(0, dp[i-1][j-1]);
                }
                dp[i][j] = take;
                if(i > 0){
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                }
                if(j > 0){
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};