class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;
        int max_len = 0;
        int max_char = 0;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            max_char = max(max_char, count[s[r]]);

            if ((r - l + 1) - max_char > k) {
                count[s[l]]--;
                l++;
            }

            max_len = max((r - l + 1), max_len);
        }

        return max_len;
    }
};
