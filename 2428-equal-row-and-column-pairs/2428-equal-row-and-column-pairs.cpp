struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<vector<int>, int, VectorHash> rowCount;

        // Count frequencies of rows
        for (const auto & row : grid)
            rowCount[row]++;

        int count = 0;

        // For each column, check how many matching rows exist
        for (int j = 0; j < n; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++)
                col.push_back(grid[i][j]);
            if (rowCount.count(col))
                count += rowCount[col];
        }
        return count;
    }
};
