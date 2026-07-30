class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int, int>> stk;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stk.empty() && stk.top().second < temperatures[i]) {
                int day = stk.top().first;
                stk.pop();

                res[day] = (i - day);
            }

            stk.push({i, temperatures[i]});
        }

        return res;
    }
};
