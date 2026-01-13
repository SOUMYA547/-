class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int s = 1 << n;
        for(int i = 0; i < s; i++){
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};