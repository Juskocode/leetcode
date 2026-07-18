class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int wildcards = 0;

        for (char move : moves) {
            if (move == '_')
                ++wildcards;
            else if (move == 'U')
                ++y;
            else if (move == 'D')
                --y;
            else if (move == 'L')
                --x;
            else if (move == 'R')
                ++x;
        }

        return abs(x) + abs(y) + wildcards;
    }
};