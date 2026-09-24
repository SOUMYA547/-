class Solution {
public:
    int reverseDegree(string s) {
        int a = 0;
        int b = s.length();
        for(int i = 0; i < b; i++){
            int r = 26 -(s[i] - 'a');
            int q = i + 1;
            a += r * q; 
        }
        return a;
    }
};