class Solution {
public:
    int mod = (7+1e9);
    int countPairs(vector<int>& array) {
        int n=array.size();
        unordered_map<int, int> mpp;
        long int count=0;
        
        for(int i=0; i<n; i++){
            mpp[array[i]]++;
            
            //For every element try & find the element if present such that the sum will be power of two.
            //Constraints: max value = 2^20 & taking sum of two elements of max value: 2*2^20
            //Check if there's present (2^0 - array[i]) or (2^1 - array[i]) or ... (2^21 - array[i])
            for(int x=0; x<=21; x++){
                mpp[array[i]]--;    //Do not count the current element again. Example: 2+2
                if(mpp.find((1<<x) - array[i])!=mpp.end()) count += mpp[((1<<x) - array[i])];
                mpp[array[i]]++;    //Reset.
            }
        }
        
        return (count%mod);
    }
};