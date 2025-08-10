class Solution {
public:
    long long specialPalindrome(long long n) {
        auto cmp = [](const string& a, const string& b) 
        {
            if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
            if (a == b) return 0;
            return a < b ? -1 : 1;
        };
        
        auto toLL = [](const string& s) 
        {
            long long x = 0;
            for (char c : s) x = x * 10 + (c - '0');
            return x;
        };
        
        auto buildMinPal = [](const array<int,10>& cnt) 
        {
            int odd = -1;
            string left, right;
            for (int d = 1; d <= 9; ++d) 
            {
                if (cnt[d] & 1) odd = d;
                left.append(cnt[d] / 2, char('0' + d));
            }
            right = left;
            reverse(right.begin(), right.end());
            return odd == -1 ? left + right : left + char('0' + odd) + right;
        };
        
        auto buildGEQ = [&](const array<int,10>& full, const string& tgt, string& out) 
        {
            int L = (int)tgt.size(), halfLen = L / 2, odd = -1;
            array<int,10> half{};
            for (int d = 1; d <= 9; ++d) {
                half[d] = full[d] / 2;
                if (full[d] & 1) odd = d;
            }
            string s(L, '?');
            
            function<bool(int,int)> dfs = [&](int i, int tight) -> bool
            {
                if (i == halfLen) 
                {
                    if (L & 1) 
                    {
                        int mid = L / 2, need = tgt[mid] - '0';
                        if (tight) 
                        {
                            if (odd < need) return false;
                            if (odd > need) tight = 0;
                        }
                        s[mid] = char('0' + odd);
                    }
                    return cmp(s, tgt) >= 0;
                }
                int need = tight ? tgt[i] - '0' : 1;
                for (int d = max(1, need); d <= 9; ++d) 
                {
                    if (!half[d]) continue;
                    s[i] = s[L - 1 - i] = char('0' + d);
                    --half[d];
                    int ntight = tight && (d == need);
                    if (dfs(i + 1, ntight)) return true;
                    ++half[d];
                }
                return false;
            };
            
            if (!dfs(0, 1)) return false;
            out = s;
            return true;
        };
    
        string best, t = to_string(n + 1);
        int lenN = (int)to_string(n).size();
    
        for (int mask = 1; mask < (1 << 9); ++mask) 
        {
            array<int,10> cnt{};
            int L = 0, oddCnt = 0;
            for (int b = 0; b < 9; ++b) if (mask & (1 << b)) 
            {
                int d = b + 1;
                cnt[d] = d; L += d; if (d & 1) ++oddCnt;
            }
            if (oddCnt > 1) continue;
    
            if (L > lenN) 
            {
                string cand = buildMinPal(cnt);
                if (best.empty() || cmp(cand, best) < 0) best = cand;
            } 
            else if (L == (int)t.size()) 
            {
                string cand;
                if (buildGEQ(cnt, t, cand))
                    if (best.empty() || cmp(cand, best) < 0) best = cand;
            }
        }
        return best.empty() ? 0LL : toLL(best);
    }
};