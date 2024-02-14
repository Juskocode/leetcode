class Solution {
public:
    double distance(long x1, long y1, long x2, long y2)
    {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }
    int bfs(vector<vector<int>> adj, int x)
    {
        int detonated = 1;
        vector<bool> visited(adj.size(), false);
        visited[x] = true;
        queue<int> q;
        q.push(x);

        while (!q.empty())
        {
            int n = q.front();q.pop();

            for (const int &dest : adj[n])
            {
                if (!visited[dest])
                {
                    visited[dest] = true;
                    detonated++;
                    q.push(dest);
                }
            }
        }
        return (detonated);
    }
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int maxBombs = 0;
        vector<vector<int>> adj(bombs.size());
        for (int i = 0; i < (int) bombs.size(); i++) 
        {
            for (int j = 0; j < (int) bombs.size(); j++) 
            {
                int x1 = bombs[i][0], y1 = bombs[i][1];
                int x2 = bombs[j][0], y2 = bombs[j][1];
                int r1 = bombs[i][2];

                if (i != j && distance(x1, y1, x2, y2) <= (double)r1 * r1)
                    adj[i].push_back(j);
            }
        }
        for (int i = 0; i < (int) bombs.size(); i++)
            maxBombs = max(maxBombs, bfs(adj, i));
        
        return (maxBombs);
    }
};
