class Solution {
public:
    int mirrorDistance(int n) {
        if(n < 0){
            return 0;
        }
        int a = n;
        int b = 0;
        while( n > 0){
            int d = n % 10;
            b = b * 10 + d;
            n /= 10;
        }
        return abs(a - b);
    }
};