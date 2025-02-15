class ProductOfNumbers {
public:
    vector<int> prefm;
    int run;
    ProductOfNumbers() {
        run = 1;
    }
    
    void add(int num) {
        if (!num) // case num is 0 discard current run
        {
            prefm.clear();
            run = 1;
            return ;
        }
        run *= num;
        prefm.push_back(run);
    }
    
    int getProduct(int k) {
        // pref sum can be shorter than the elements due to '0' discards
        int runSize = prefm.size();
        if (runSize < k) return 0; // k is from the discarded values
        if (runSize == k) return run; // max value
        return run / prefm[runSize - 1 - k]; // to get get the k value divided from the run the run until pos k
    }
};
