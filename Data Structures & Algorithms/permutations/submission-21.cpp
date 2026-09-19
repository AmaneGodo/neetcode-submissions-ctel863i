class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() <= 0) {
            return {{}};
        }

        vector<int> temp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> res;
        vector<vector<int>> perms = permute(temp);

        for (const auto& p : perms) {
            for (int i = 0; i < p.size() + 1; i++) {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                res.push_back(p_copy);
            }
        }

        return res;
    }
};
