class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++)
            s.insert(i);
    }
    
    int popSmallest() {
        auto it = s.begin();
        if (it == s.end())
            return 0;
        int minVal = *(it);
        s.erase(it);
        return minVal;
    }
    
    void addBack(int num) {
        auto it = s.find(num);
        if (it != s.end())
            return ;
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */