class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        int start = t - 3000, end = t;
        unsigned count = 0;
        q.push(t);
        queue<int> re = q;

        while (!re.empty())
        {
            int cur = re.front();re.pop();
            if (cur >= start && cur <= end)
                count++;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */