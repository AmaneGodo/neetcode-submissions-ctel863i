class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHq;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int n : nums) {
            minHq.push(n);

            if (minHq.size() > k) {
                minHq.pop();
            }
        }
    }
    
    int add(int val) {
        minHq.push(val);

        if (minHq.size() > k) {
            minHq.pop();
        }

        return minHq.top();
    }
};
