class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        
        std::unordered_set<char> seen;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.length(); r++) {
            while (seen.find(s[r]) != seen.end()) {
                seen.erase(s[l]);
                l++;
            }

            seen.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
