class Solution {
public:
    int digitSquareSum(int n){
        int s = 0;

        while(n > 0){
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1){
            if(seen. count(n)){
                return false;
            }
            seen.insert(n);
            n = digitSquareSum(n);
        }
        return true;
    }
};