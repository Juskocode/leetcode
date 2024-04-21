#define node tuple<int, int, int>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size(), m = heights[0].size();
        
        priority_queue<node,vector<node>,greater<node>> pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        pq.push({0,0,0});
        int dirs[] = {0, 1, 0, -1, 0};

        while(!pq.empty())
        {
            auto [cost, x, y] = pq.top();pq.pop();

            if(x == n - 1 && y == m - 1)
                return cost;

            for(int i = 0; i < 4; i++)
            {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int newEffort = max(abs(heights[x][y] - heights[nx][ny]), cost);

                    if(dist[nx][ny] > newEffort)
                    {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, nx, ny});
                    }
                }
            }
        }
        return 0;
    }
};
