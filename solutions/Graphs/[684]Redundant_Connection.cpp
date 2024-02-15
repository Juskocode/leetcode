class Solution {
public:
    int parent[4001];
    int rank[4001];

    void make(int v)
    {
        parent[v] = v;
        rank[v] = 1;
    }

    int findParent(int a)
    {
        if (a == parent[a])
            return (a);
        return (parent[a] = findParent(parent[a]));
    }

    void Union(int a, int b)
    {
        a = findParent(a);
        b = findParent(b);

        if (a == b)
            return ;
        
        if (rank[a] < rank[b])
            swap(a, b);
        
        parent[b] = a;
        rank[a] += rank[b];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        for (int i = 1; i <= n; i++)
            make(i);
        for (int i = 0; i < n; i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            int a = findParent(src);
            int b = findParent(dest);
            if (a == b)
                return {src, dest};
            else
                Union(src, dest);
        }
        return {};
    }
};
