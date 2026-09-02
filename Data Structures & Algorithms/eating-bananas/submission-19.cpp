class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = 0;
        int k = 0;

        while (l <= r) {
            k = (l + r) / 2;
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
