class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;

        for (const auto& n : nums) {
            count[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for (auto& pair : count) {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> res;

        for (int i = freq.size() - 1; i > 0; i--) {
            for (const auto& n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
    }
};
