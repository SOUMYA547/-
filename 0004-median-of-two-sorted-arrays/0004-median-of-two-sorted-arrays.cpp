class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        int l = 0;
        int r = m;
        if(m > n){
            return findMedianSortedArrays(b, a);
        }
        while(l <= r){
            int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
            int x = (i == 0) ? INT_MIN : a[i - 1];
            int y = (i == m) ? INT_MAX : a[i];
            int p = (j == 0) ? INT_MIN : b[j - 1];
            int q = (j == n) ? INT_MAX : b[j];

            if(x <= q && p <= y){
                if((m + n) % 2)
                    return max(x, p);
                return (max(x, p) + (double)min(y, q)) / 2;
            }
            if(x > q) r = i - 1;
            else l = i + 1;
        }
        return 0;
    }
};