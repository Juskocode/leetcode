#define ull unsigned long long

class Solution {
public:
    //top k element in klogn
    long long maxScore(vector<int>& n1, vector<int>& n2, int k) {
        ull score = 0, curr = 0;
        vector<pair<int, int>> v(n1.size());
        for(int i = 0; i < n1.size(); i++)
            v[i] = {n2[i], n1[i]};
        //sort like min heap to have top k (find highest min in k window)
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [v1, v2] : v)
        {
            pq.push(v2);
            curr += v2;
            if (pq.size() > k)
            {
                curr -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
                score = max(score, curr * v1);
        }
        return score;
    }
};