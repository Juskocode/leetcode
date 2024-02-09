class Solution {
public:

	void floodFill(vector<vector<char>> &grid, int i, int j)
	{
		if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] != '1')
			return ;
		
		grid[i][j] = 0; // mark as visited in the 'flood fill'
		floodFill(grid, i + 1, j);
		floodFill(grid, i - 1, j);
		floodFill(grid, i, j + 1);
		floodFill(grid, i, j - 1);
	}

	int numIslands(vector<vector<char>>& grid) 
	{
		int islandsCount = 0;

		if (grid.empty())
			return (0);

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					islandsCount++;
					floodFill(grid, i, j);
				}
			}
		}
		return (islandsCount);
	}
};

