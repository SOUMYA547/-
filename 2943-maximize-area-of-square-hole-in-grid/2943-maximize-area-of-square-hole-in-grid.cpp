class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        // Helper function to find longest consecutive sequence
        auto longestConsecutive = [](vector<int>& bars) {
            if (bars.empty()) return 1;

            sort(bars.begin(), bars.end());

            int longest = 1;
            int current = 1;

            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    current++;          // consecutive bar
                } else {
                    current = 1;        // break in sequence
                }
                longest = max(longest, current);
            }

            return longest + 1; // bars removed + 1 = cells formed
        };

        // Find maximum height and width
        int maxHeight = longestConsecutive(hBars);
        int maxWidth = longestConsecutive(vBars);

        // Side of the largest square
        int side = min(maxHeight, maxWidth);

        // Area of square
        return side * side;
    }
};
