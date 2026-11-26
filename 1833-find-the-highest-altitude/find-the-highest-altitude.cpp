class Solution {
public:
    int largestAltitude(vector<int>& g){
        int a = 0;
        int m = 0;
        int n = g.size();
        for(int i = 0; i < n; i++){
            a += g[i];
            m = max(m, a);
        }
        return m;
    }
};