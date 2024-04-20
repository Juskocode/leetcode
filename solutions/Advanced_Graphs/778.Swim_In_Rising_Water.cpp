class Node {
public:    
    int time;
    int x;
    int y;
    
};

bool operator< (const Node &a, const Node &b) {
    return a.time > b.time;
}

struct pair_hash {
    inline std::size_t operator() (const std::pair<int,int> & v) const {
        return v.first * 31 + v.second;
    }
};

class Solution {
public:
    int dirs[5] = {1, 0, -1, 0, 1};
    bool isInside(int i , int j, int m, int n)
    {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        unordered_set<pair<int, int>, pair_hash> seen;
        int m = grid.size(), n = grid[0].size();
        int maxCost = 0;
        priority_queue<Node> pq;
        pq.push({grid[0][0], 0, 0});
        seen.insert({0, 0});

        while (!pq.empty())
        {
            Node node = pq.top();pq.pop();
            maxCost = max(maxCost, node.time);
            if (node.x == m - 1 && node.y == n - 1)
                return maxCost;

            for (int i = 0; i < 4; i++)
            {
                int dx = node.x + dirs[i];
                int dy = node.y + dirs[i + 1];

                if (seen.count({dx, dy}) <= 0 && isInside(dx, dy, m, n))
                {
                    pq.push({grid[dx][dy], dx, dy});
                    seen.insert({dx, dy});
                }
            }
        }
        return maxCost;
    }
};
