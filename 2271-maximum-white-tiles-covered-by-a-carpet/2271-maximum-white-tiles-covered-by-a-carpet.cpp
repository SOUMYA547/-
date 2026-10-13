class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size(), l = 0, r = 0;
        int c = 0, a = 0;
        while(l < n){
            long long end = (long long)tiles[l][0] + carpetLen - 1;
            while(r < n && tiles[r][1] <= end){
                c += tiles[r][1] - tiles[r][0] + 1;
                r++;
            }
            int p = 0;
            if(r < n && tiles[r][0] <= end)
            p = end - tiles[r][0] + 1;
            a = max(a, c + p);
            c -= tiles[l][1] - tiles[l][0] + 1;
            l++;
        }
        return a;
    }
};