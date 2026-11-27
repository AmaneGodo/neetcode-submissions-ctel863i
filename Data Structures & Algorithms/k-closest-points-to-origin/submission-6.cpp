class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> dp_mp(comp);

        for (auto p : points) {
            dp_mp.push({p[0], p[1]});
        }

        vector<vector<int>> res;

        for (int i = 0; i < k; i++) {
            res.push_back(dp_mp.top());
            dp_mp.pop();
        }

        return res;
    }
};
