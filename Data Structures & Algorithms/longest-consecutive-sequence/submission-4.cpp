class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen(nums.begin(), nums.end());

        int longest = 0;
        int length = 1;

        for (int n : nums) {
            if (seen.find(n - 1) == seen.end()) {
                length = 1;

                while (seen.find(n + length) != seen.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
