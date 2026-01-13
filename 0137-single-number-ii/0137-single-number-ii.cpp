class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a  = 0;
        for(int b = 0; b < 32; b++){
            int c = 0;
            for(int x : nums){
                if((x >> b) & 1){
                    c++;
                }
            }
            if(c % 3 != 0){
                a |= (1 << b);

            }
        }
        return a;
    }
};