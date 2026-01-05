class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int val = matrix[i][j];
                if(val < 0) negCount++;
                int absVal = abs(val);
                totalSum += absVal;
                minAbs = min(minAbs, absVal);
            }
        }
        if(negCount % 2 == 1){
            totalSum -= 2LL * minAbs;
        }
        return totalSum;
    }
};