class RecentCounter {
public:
    queue<int> calls;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        constexpr int dt = 3000;
        calls.push(t);
        while (!calls.empty() && calls.front() < t - dt)
            calls.pop();
        return calls.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */