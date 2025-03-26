class Solution {
public:

    int ops(vector<int> &v, int mid, int x)
    {
        int count = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == mid) continue;
            int diff = abs(v[i] - mid);
            //check for invalid case
            if (v[i] % x != mid % x)
                return -1;
            count += (diff / x);
        }
        return count;
    }

    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        if (n * m < 2) return 0;
        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                v.push_back(grid[i][j]);
            }
        }
        
        sort(v.begin(), v.end());

        int mid = v[(v.size() / 2)], count = 0;
        if (v.size() % 2 == 0)
            count = min(ops(v, v[v.size() / 2 - 1], x), ops(v, v[v.size() / 2], x));
        else
            count = ops(v, mid, x);
        return count;
    }
};