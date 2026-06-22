class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int pre = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = pre;
            pre *= nums[i];
        }

        int post = 1;
        for (int i = res.size() - 1; i > -1; i--) {
            res[i] = res[i] * post;
            post = nums[i] * post;
        }

        return res;
    }
};
