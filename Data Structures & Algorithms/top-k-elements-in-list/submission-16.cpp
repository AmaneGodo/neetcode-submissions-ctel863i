class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;

        for (int n : nums) {
            count[n]++;
        }

        vector<vector<int>> frq(nums.size() + 1);

        for (auto& pair : count) {
            frq[pair.second].push_back(pair.first);
        }

        vector<int> res;

        for (int i = frq.size() - 1; i > 0; i--) {
            for (auto& n : frq[i]) {
                res.push_back(n);

                if (res.size() == k) {
                    return res;
                }
            }
        }
    }
};
