class FoodRatings {
public:
    struct Cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first < b.first;   // higher rating first
            return a.second > b.second;                         // smaller name first
        }
    };

    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, Cmp>> listenings;
    unordered_map<string, string> foodCuisines;
    unordered_map<string, int> foodRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); ++i) {
            listenings[cuisines[i]].emplace(ratings[i], foods[i]); // (int, string)
            foodCuisines[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
        
    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        listenings[foodCuisines[food]].emplace(newRating, food);
        
    }
    
    string highestRated(string cuisine) {
        auto cand = listenings[cuisine].top();

        while (foodRating[cand.second] != cand.first) {
            listenings[cuisine].pop();
            cand = listenings[cuisine].top();
        }
        return cand.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */