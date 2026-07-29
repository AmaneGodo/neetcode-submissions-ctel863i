class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> count;   
        int l = 0;
        int res = 0;
        int most_frq = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            most_frq = max(most_frq, count[s[r]]);

            while ((r - l + 1) - most_frq > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
