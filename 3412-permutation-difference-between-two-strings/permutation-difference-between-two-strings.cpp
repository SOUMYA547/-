class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int a = s.length();
        int b = 0;
        for(int i = 0; i < a; i++){
            int p = t.find(s[i]);
            b += abs(i - p);
        }
        return b;
    }
};