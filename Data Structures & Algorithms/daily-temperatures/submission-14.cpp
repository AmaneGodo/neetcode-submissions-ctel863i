class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<pair<int, int>> stack;
        vector<int> res(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!stack.empty() && temperatures[i] > stack.top().second) {
                int day = stack.top().first;
                stack.pop();

                res[day] = i - day;
            }

            stack.push({i, temperatures[i]});
        }

        return res;
    }
};
