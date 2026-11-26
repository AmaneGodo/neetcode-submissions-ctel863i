class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> maxHeap(comp);

        for (const auto& p : points) {
            maxHeap.push({p[0], p[1]});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return res;
    }
};
