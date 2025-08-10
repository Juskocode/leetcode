class Solution {
public:
    int sortPermutation(vector<int>& v) {
        vector<int> w;
        w.reserve(v.size());
        for (int i = 0; i < v.size(); i++)
            if (v[i] != i)
                w.push_back(i);
        if (w.empty())
            return 0;
        return accumulate(next(w.begin()), w.end(), w[0], [](int a, int b) {return a & b;});
    }
};