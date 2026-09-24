class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stk;

        bt(res, stk, 0, 0, n);
        return res;
    }

    void bt(vector<string>& res, string& stk, int openN, int closeN, int n) {
        if (openN == n && closeN == n) {
            res.push_back(stk);
            return;
        }

        if (openN < n) {
            stk += '(';
            bt(res, stk, openN + 1, closeN, n);
            stk.pop_back();
        }

        if (closeN < openN) {
            stk += ')';
            bt(res, stk, openN, closeN + 1, n);
            stk.pop_back();
        }
    }
};
