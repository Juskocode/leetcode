class Solution {
public:
    int countDays(int days, vector<vector<int>>& ve) {
        int freedays = 0, latest = 0;

        sort(ve.begin(), ve.end());
        for (const auto &v : ve)
        {
            if (v[0] > latest + 1)
                freedays += v[0] - latest - 1;
            latest = max(latest, v[1]);
        }
        freedays += days - latest;
        return freedays;
    }
};