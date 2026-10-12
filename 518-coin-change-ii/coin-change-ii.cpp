
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const int LIMIT = INT_MAX;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                long long ways = (long long)dp[j] + dp[j - coin];
                dp[j] = min(ways, (long long)LIMIT);
            }
        }

        return dp[amount];
    }
};


