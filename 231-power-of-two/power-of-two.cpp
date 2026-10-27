class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        for(int i = 0; i < n; i++){
            while(n % 2 == 0){
                n /= 2;
            }
            return n == 1;
        }
        return false;
    }
};