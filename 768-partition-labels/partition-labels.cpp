class Solution {
public:
    vector<int> partitionLabels(string s) {
        int l[26] = {0};
        for(int i = 0; i < s.length(); i++){
            l[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0;
        int e = 0;
        for(int i = 0; i < s.length(); i++){
            e = max(e, l[s[i] - 'a']);
            if(i == e){
                ans.push_back(e - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};