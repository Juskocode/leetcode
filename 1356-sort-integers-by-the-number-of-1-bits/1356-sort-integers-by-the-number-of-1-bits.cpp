class Solution {
public:
    // 1001
    // LB -> if its 1 (1001 & 0001) -> 1
    // 0100 -> if its 1 (0100 & 0001) -> 0
    // 0010 -> if its 1 (0010 & 0001) -> 0
    // 0001 -> if its 1 (0001 & 0001) -> 1
    // 6 -> 0110
    int computeNbits(const int &val) {
        int p = val, b = 0;
        while (p) {
            if (p & 1)
                b++;
            p >>= 1;
        }
        return b;   
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> container;
        vector<int> res;

        for (const int & val : arr) {
            container.push_back({computeNbits(val), val});
            cout << computeNbits(val) << " " << val << endl;
        }
        
        sort(container.begin(), container.end());

        for (const auto & val : container)
            res.push_back(val.second);
        
        return res;
    }
};