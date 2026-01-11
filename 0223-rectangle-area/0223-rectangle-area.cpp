class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA, areaB, total1, total2, overLapArea, overLapLength, overLapWidth;
        areaA = (ax2 - ax1) * (ay2 - ay1);
        areaB = (bx2 - bx1) * (by2 - by1);
        overLapWidth = min(ax2, bx2) - max(ax1, bx1);
        overLapLength = min(ay2, by2) - max(ay1, by1);
        if(overLapWidth <= 0 || overLapLength <= 0){
            overLapArea = 0;
        }
        else{
            overLapArea = overLapWidth * overLapLength;
        }
        total1 = areaA + areaB;
        total2 = areaA + areaB - overLapArea;
        if(overLapArea == 0){
            return total1;
        }
        else {
            return total2;
        }
    }
};