class RecentCounter {
public:
    deque<int> q;
    unsigned count = 0;

    RecentCounter() {
        
    }
    
    int ping(int t) {
        q.push_back(t);count++;
        while (q.front() < t - 3000) {
            q.pop_front();
            count--;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */