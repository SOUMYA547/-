class Solution {
public:
    int maxOperations(vector<int>& n, int k) {
        sort(n.begin(), n.end());
        int l = 0;
        int r = n.size() - 1;
        int c = 0;
        while(l < r){
            int s = n[l] + n[r];
            if(s == k){
                c++;
                l++;
                r--;
            }
            else if(s < k){
                l++;
            }
            else{
                r--;
            }
        }
        return c;
    }
};