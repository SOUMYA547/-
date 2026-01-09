class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {    
        int n = points.size();
        if(n <= 2) return n;
        int a = 0;
        for(int i = 0; i < n; i++){
            map<pair<int, int>, int> mp;
            int duplicate = 0;
            int currMax = 0;

            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(x1 == x2 && y1 == y2){
                    duplicate++;
                    continue;
                }
                int dy = y2 - y1;
                int dx = x2 - x1;

                int g = gcd(dy, dx);
                dy /= g;
                dx /= g;

                mp[{dy, dx}]++;
                currMax = max(currMax, mp[{dy, dx}]);
            }
            a = max(a, currMax + duplicate + 1);
        }
        return a;
    }
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};