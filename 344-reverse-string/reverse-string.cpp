class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int a = s.size();
        int r = a - 1;
        while(l < r){
            swap(s[l], s[r]);
            l++;
            r--;
        } 
    }
};