class Solution {
    static constexpr double EPS = 1e-6;

    bool solve(vector<double> a) {
        if (a.size() == 1) return fabs(a[0] - 24.0) < EPS;

        // try every ordered pair (i, j)
        for (int i = 0; i < (int)a.size(); ++i) {
            for (int j = 0; j < (int)a.size(); ++j) if (i != j) {
                vector<double> rest;
                rest.reserve(a.size() - 1);
                for (int k = 0; k < (int)a.size(); ++k)
                    if (k != i && k != j) rest.push_back(a[k]);

                // candidates from a[i], a[j]
                double x = a[i], y = a[j];
                vector<double> cands = { x + y, x - y, y - x, x * y };
                if (fabs(y) > EPS) cands.push_back(x / y);
                if (fabs(x) > EPS) cands.push_back(y / x);

                for (double v : cands) {
                    rest.push_back(v);
                    if (solve(rest)) return true;
                    rest.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> a(cards.begin(), cards.end());
        return solve(a);
    }
};
