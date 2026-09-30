class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string curStr;
        std::unordered_map<int, string> mp = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        if (digits.length() > 0) {
            bt(res, mp, digits, curStr, 0);
        }
        return res;
    };

    void bt(vector<string>& res, std::unordered_map<int, string>& mp, string digits, string curStr, int i) {
        if (digits.length() == curStr.length()) {
            res.push_back(curStr);
            return;
        }

        for (auto& c : mp[digits[i] - '0']) {
            bt(res, mp, digits, curStr + c, i + 1);
        }
    }
};
