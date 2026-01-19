class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = 0;
        for(int c : candies){
            maxCandies = max(maxCandies, c);
        }
        vector<bool> result;
        for(int i = 0; i < n; i++){
            result.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return result;
    }
};