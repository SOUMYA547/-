class Solution {
public:
    string reformatNumber(string number) {
        string d = "";
        for(char c : number){
            if(c >= '0' && c <= '9'){
                d += c;
            }
        }
        string a = "";
        int i = 0;
        int n = d.size();
        while(n - i > 4){
            a += d.substr(i, 3) + "-";
            i += 3;
        }
        int r = n - i;
        if (r == 4){
            a += d.substr(i, 2) + "-";
            a += d.substr(i + 2, 2);
        }
        else{
            a += d.substr(i, r);
        }
        return a;
    }
};