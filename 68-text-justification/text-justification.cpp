class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i = 0;
        while(i < words.size()){
            int j = i;
            int len = 0;
            while(j < words.size() && len + words[j].size() + (j - i) <= maxWidth){
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            if(j == words.size() || gaps == 0){
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k < j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else{
                int spaces = maxWidth - len;
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;

                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k < j - 1){
                        line += string(spaceEach + (extra > 0), ' ');
                        extra--;
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};