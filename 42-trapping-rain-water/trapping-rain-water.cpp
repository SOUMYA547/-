class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int m = 0, n = 0;
        int w = 0;
        while (l < r){
            if(height[l] < height[r]){
                m = max(m, height[l]);
                w += m - height[l];
                l++;
            } else {
                n = max(n, height[r]);
                w += n - height[r];
                r--;
            }
        }
        return w;
    }
};