class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> stack;
        vector<pair<int, int>> ps;

        for (int i = 0; i < position.size(); i++) {
            ps.push_back({position[i], speed[i]});
        }

        double time = 0;
        sort(ps.begin(), ps.end());

        for (int i = ps.size() - 1; i > -1; i--) {
            time = static_cast<double>(target - ps[i].first) / ps[i].second;

            if (!stack.empty() && stack.top() >= time) {
                continue;
            }

            stack.push(time);
        }
        
        return stack.size();

    }
};
