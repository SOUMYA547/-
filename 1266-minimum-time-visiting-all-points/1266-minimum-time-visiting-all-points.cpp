class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int t = 0;
        int n = points.size();
        for(int i = 1; i < n; i++){
            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);
            t  += max(dx, dy);
        }
        return t;
    }
};