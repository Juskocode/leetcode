class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};

        vector<int> grp(n), idg(n);

        for (auto& e : edges) {
            grp[e[0]] ^= e[1];
            grp[e[1]] ^= e[0];
            idg[e[0]]++; idg[e[1]]++;
        }

        queue<int> q;
        
        for (int i = 0; i<n; i++) {
            if (idg[i]==1) q.emplace(i);
        }

        while(n > 2) {
            int size = q.size();
            n -=size;
            
            while(size--){
                int x = q.front(); q.pop();
                int nei = grp[x];
                grp[nei] ^= x;
                if (--idg[nei] == 1) q.emplace(nei);
            }
        }
        vector<int> res;
        while(!q.empty()) {
            res.emplace_back(q.front());q.pop();
        }

        return res;
    }
};