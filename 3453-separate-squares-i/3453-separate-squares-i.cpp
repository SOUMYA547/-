class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0.0;
        double low = 1e18, high = -1e18;
        for(auto &sq : squares){
            double y = sq[1];
            double l = sq[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }
        double half = totalArea/2.0;
        for(int i = 0; i < 100; i++){
            double mid = (low + high) / 2.0;
            double below = 0.0;

            for(auto &sq : squares){
                double y = sq[1];
                double l = sq[2];
                if(mid <= y){
                    continue;
                } else if(mid >= y + l){
                    below += l * l;
                } else {
                    below += l * (mid - y);
                }
            }
            if(below < half){
                low = mid;
            } else{
                high = mid;
            }
        }
        return low;
    }
};