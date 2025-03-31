
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        map<int, long long> meals;
        set<int> powerOfTwo;
		
		//Power_array to store power of 2
        for(int i = 0; i <= 21; i++) {
            powerOfTwo.insert(1<<i);
        }
        long long res = 0;
		
		//store meals with there count 
        for(int num : deliciousness) {
            meals[num]++;
        }

		//for each meal we will check if there exist any other meal that sums to good meal.
        for(auto meal : meals) {
		
		// Loop from lower bound of square value of meal till end 
		// example if  meal 4 then we will search lower bound of 16 in our stored power array.
            for(auto num = powerOfTwo.lower_bound(meal.first<<1); num != powerOfTwo.end(); num++) {
			
				// checking lower bound of *num - meal.first exist in meals.
				//example : num = 16 , meal.first = 1 then we will check for 15
                auto it = meals.lower_bound(*num - meal.first);
                if(it == meals.end())
				//if not found break
                    break;
					
				// if we found the number we are searching  i.e  15(it.first) + 1(meal.first) == 16(num) then we will calculate the result
                if(it->first + meal.first == *num) {
				
					// to calculate ways  
                    if(it->first == meal.first)
                        res += it->second * (meal.second - 1) / 2;
                    else
                        res += it->second * meal.second;
                }
            }
        }

        return res % 1000000007;
    }
};