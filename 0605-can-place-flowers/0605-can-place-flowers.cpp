class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for(int i = 0; i < m; i++){
            if(flowerbed[i] == 0){
                int l = (i == 0) ? 0 : flowerbed[i - 1];
                int r = (i == m - 1) ? 0 : flowerbed[i + 1];
                if(l == 0 && r == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }
                if(n <= 0) return true;
        }
        return false;
    }
};