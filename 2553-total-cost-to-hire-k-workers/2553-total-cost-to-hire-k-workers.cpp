#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;

        // min-heaps
        priority_queue<int, vector<int>, greater<int>> left, right;

        int i = 0;         // next index to add on the left
        int j = n - 1;     // next index to add on the right

        // preload up to `candidates` from each side, without overlapping
        for (int t = 0; t < candidates && i <= j; ++t) left.push(costs[i++]);
        for (int t = 0; t < candidates && i <= j; ++t) right.push(costs[j--]);

        for (int hired = 0; hired < k; ++hired) {
            int lc = left.empty()  ? INT_MAX : left.top();
            int rc = right.empty() ? INT_MAX : right.top();

            // tie goes to left → smaller index
            if (lc <= rc) {
                ans += lc; left.pop();
                if (i <= j) left.push(costs[i++]);  // refill from left side
            } else {
                ans += rc; right.pop();
                if (i <= j) right.push(costs[j--]); // refill from right side
            }
        }
        return ans;
    }
};
