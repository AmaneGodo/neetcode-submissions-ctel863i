class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHq;

        for (auto n : nums) {
            minHq.push(n);
            if (minHq.size() > k) {
                minHq.pop();
            }
        }

        return minHq.top();
    }
};
