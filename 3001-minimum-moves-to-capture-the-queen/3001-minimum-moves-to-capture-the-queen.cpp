class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a == e){
            if(c != a || (d - b) * (d - f) > 0)
            return 1;
        }
        if(b == f){
            if(d != b || (c - a) * (c - e) > 0)
            return 1;
        }
        if(abs(c - e) == abs(d - f)){
            if(abs(a - e) != abs(b - f) || 
            (a - c) * (a - e) > 0 || 
            (b - d) * (b - f) > 0)
            return 1;
        }
        return 2;
    }
};