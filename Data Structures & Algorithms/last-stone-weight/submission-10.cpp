class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHq;

        for (int s : stones) {
            maxHq.push(s);
        }

        while (maxHq.size() > 1) {
            auto first = maxHq.top(); maxHq.pop();
            auto second = maxHq.top(); maxHq.pop();

            if (first - second > 0) {
                maxHq.push(first - second);
            }
        }

        if (maxHq.empty()) {
            return 0;
        } else {
            return maxHq.top();
        }
    }
};
