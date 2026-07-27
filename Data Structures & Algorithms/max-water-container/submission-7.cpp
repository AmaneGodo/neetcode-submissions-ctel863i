class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int area;
        int maxArea = 0;

        while (l < r) {
            area = min(heights[l], heights[r]) * (r - l);
            maxArea = max(area, maxArea);

            if (heights[l] <= heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxArea;
    }
};
