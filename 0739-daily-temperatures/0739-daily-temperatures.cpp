class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> v(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i])
                s.pop();
            v[i] = (s.empty()) ? 0 : (s.top() - i);
            s.push(i);
        }
        return v;
    }
};