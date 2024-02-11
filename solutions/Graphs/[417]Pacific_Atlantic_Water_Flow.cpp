class Solution {
public:
    int m, n;
    vector<int> dir = {0, 1, 0, -1, 0};
    queue<pair<int,int>> pac;
    queue<pair<int,int>> atl;
    
    bool isInside(int x, int y){
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    
    void bfs(queue<pair<int,int>> &q, vector<vector<int>> &vis, vector<vector<int>>& matrix)
    {
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vis[x][y] = 1;

            for (int i = 0; i < 4; i++)
            {
                int dx = x + dir[i];
                int dy = y + dir[i + 1];
                // water can only flow the parent cell is the childs have less than or equal to height
                if (isInside(dx,dy) && matrix[x][y] <= matrix[dx][dy] && !vis[dx][dy]) 
                    q.push({dx,dy});
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> ans;
        m = matrix.size();
        n = matrix[0].size();
 
        vector<vector<int>> visp(m, vector<int>(n,0));
        vector<vector<int>> visq(m, vector<int>(n,0));

        // top and left edges (pacific)
        for (int i = m - 1; i >= 0; i--)
            pac.push({i, 0});
        for (int i = n - 1; i >= 0; i--)
            pac.push({0, i});
        
        // bottom and right edges (atlantic)
        for (int i = m - 1; i >= 0; i--)
            atl.push({i, n - 1});
        for (int i = n - 1; i >= 0; i--)
            atl.push({m - 1, i});
        
        //check cells that can reach the pacific
        bfs(pac, visp, matrix);
        //check cells that can reach the atlantic
        bfs(atl, visq, matrix);
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                //if the current cell can reach both pacific and atlantic then it's a solution
                if (visp[i][j] && visq[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
