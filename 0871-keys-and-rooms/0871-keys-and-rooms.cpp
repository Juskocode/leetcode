class Solution {
public:
    unsigned c = 0;
    void dfs(int v, vector<bool> &vis, vector<vector<int>>& rooms)
    {
        vis[v] = true;c++;
        for (const auto &u : rooms[v])
            if (!vis[u])
                dfs(u, vis, rooms);
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        vector<bool> vis(n);
        dfs(0, vis, rooms);
        return n == c;
    }
};