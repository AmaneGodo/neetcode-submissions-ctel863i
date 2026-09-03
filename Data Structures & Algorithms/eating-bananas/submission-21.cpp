class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int res = 0;

        while (l <= r) {
            int k = (l + r) / 2;
            int time = 0;

            for (auto& p : piles) {
                time += ceil(static_cast<double>(p) / k);
            }

            if (time <= h) {
                res = k;
                r = k - 1;
            }

            else {
                l = k + 1;
            }
        }

        return res;
    }
};
