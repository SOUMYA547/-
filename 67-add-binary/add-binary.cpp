class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        long long int i = a.size() - 1;
        long long int j = b.size() - 1;
        long long int c = 0;
        while(i >= 0 || j >= 0 || c){
            long long int s = c;
            if(i >= 0){
                s += a[i] - '0';
                i--;
            }
            if(j >= 0){
                s += b[j] - '0';
                j--;
            }
            ans += char((s % 2) + '0');
            c = s / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};