class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        
        double slope;
        int maxPoints = 0;

        for (int i = 0; i < p.size(); i++) {
            unordered_map<double, int> match;
            for (int j = i + 1; j < p.size(); j++) {
                // (0, 0) skip
                if ((p[j][0] - p[i][0]) == 0 && (p[j][1] - p[i][1]) == 0)
                    continue;
                if ((p[j][0] - p[i][0]) != 0)
                    slope = (double)(p[j][1] - p[i][1]) / (p[j][0] - p[i][0]);
                else
                    slope = 1e5;
                match[slope]++;
                maxPoints = max(maxPoints, match[slope]);
            }
        }
        return maxPoints + 1;
    }
};