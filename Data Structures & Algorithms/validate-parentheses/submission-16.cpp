class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
            };

        for (char c : s) {
            if (mp[c]) {
                if (!stack.empty() && stack.top() == mp[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            }
            else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};
