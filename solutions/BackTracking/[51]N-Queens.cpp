class Solution {
public:
    int	is_safe_search(vector<int> tab, int x, int y)
    {
        for (int i = 0; i < x; i++)
            if (y == tab[i]
                || i + tab[i] == x + y
                || i - tab[i] == x - y)
                return (0);
        return (1);
    }

    void	backtrack(vector<int> &tab, int pos, vector<vector<int>> &tabs)
    {

        if (pos == tab.size())
        {
            tabs.push_back(tab);
            return ;
        }
        for (int i = 0; i < tab.size(); i++)
        {
            if (is_safe_search(tab, pos, i))
            {
                tab[pos] = i;
                backtrack(tab, pos + 1, tabs);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<int> tab(n, -1);
        vector<vector<int>> tabs;
        backtrack(tab, 0, tabs);

        vector<vector<string>> result(tabs.size(), vector<string>(n, string(n, '.')));
         
        for (int i = 0; i < tabs.size(); i++)
        {
            for (int j = 0; j < n; j++)
            {
                result[i][tabs[i][j]][j] = 'Q';
            }
        }
        return (result);
    }
};
