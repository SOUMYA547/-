
class Solution {
public:
    int countEven(int num) {
        int sum = 0;
        int n = num;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        int ans = num / 2;
        if (num % 2 == 0 && sum % 2 != 0) {
            ans--;
        }

        return ans;
    }
};
