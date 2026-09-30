class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;

        bt(res, part, s, 0);
        return res;
    }

    bool isPali(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    void bt(vector<vector<string>>& res, vector<string>& part, string s, int i) {
        if (i >= s.length()) {
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                bt(res, part, s, j + 1);
                part.pop_back();
            }
        }
    }
};
