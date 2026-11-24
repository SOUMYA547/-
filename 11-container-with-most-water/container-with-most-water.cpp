class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int r = h.size() - 1;
        int m = 0;
        while(l < r){
            int w = r - l;
            int b = min(h[l], h[r]);
            int a = w * b;
            m = max(m, a);
            if(h[l] < h[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return m;
    }
};