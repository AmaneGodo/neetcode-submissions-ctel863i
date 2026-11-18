class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHq;

        for (int s : stones) {
            maxHq.push(s);
        }

        while (maxHq.size() > 1) {
            int first = maxHq.top();
            maxHq.pop();
            int second = maxHq.top();
            maxHq.pop();

            if (first - second > 0) {
                maxHq.push(first - second);
            }
        }

        if (maxHq.size() > 0) {
            return maxHq.top();
        } else {
            return 0;
        }
    }
};
