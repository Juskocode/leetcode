
class Solution {
public:
    bool rotate_90(vector<vector<int>>& mat, const vector<vector<int>>& target) {
        int n = mat.size(), diff = 0;
        
        // Transpose the matrix
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        // Reverse each row
        for (int i = 0; i < n; ++i) {
            reverse(mat[i].begin(), mat[i].end());
            if (!equal(mat[i].begin(), mat[i].end(), target[i].begin()))
                diff++;
        }

        return !diff;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 360/90; i++)
            if (rotate_90(mat, target))
                return true;
        return false;
    }
};