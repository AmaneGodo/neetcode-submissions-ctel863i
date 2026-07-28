class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }

        int l = 0;
        int res = 0;
        std::unordered_set<char> seen;

        for (int r = 0; r < s.length(); r++) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            res = max(res, static_cast<int>(seen.size()));
        }

        return res;
    }
};
