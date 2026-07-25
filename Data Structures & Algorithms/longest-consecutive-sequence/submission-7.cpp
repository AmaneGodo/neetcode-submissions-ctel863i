class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> contents(nums.begin(), nums.end());
        int length = 1;
        int longest = 0;

        for (int n : nums) {
            if (contents.find(n - 1) == contents.end()) {
                length = 1;

                while (contents.find(n + length) != contents.end()) {
                    length++;
                }
            }

            longest = max(longest, length);
        }

        return longest;
    }
};
