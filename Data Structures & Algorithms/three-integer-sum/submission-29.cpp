class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l;
        int r;
        int sm;
        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            l = i + 1;
            r = nums.size() - 1;

            while (l < r) {
                sm = nums[i] + nums[l] + nums[r];

                if (sm < 0) {
                    l++;
                }
                else if (sm > 0) {
                    r--;
                }
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    r -= 1;

                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return res;
    }
};
