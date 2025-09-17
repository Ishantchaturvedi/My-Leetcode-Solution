using item = pair<int, string>;//(rating, food), (rating, cuisine)
struct cmp {
    bool operator()(const item& x, const item& y) const {
        return (x.first==y.first)? x.second < y.second: x.first > y.first;
    }
};
static uint64_t key(const string& s){
    uint64_t ans=0;
    for(char c: s)
        ans=(ans<<5)+c-'a';
    return ans;
}
class FoodRatings {
    unordered_map<int, set<item, cmp>> Rated;
    unordered_map<int, item> mp;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        const int n=foods.size();
        mp.reserve(n);
        Rated.reserve(n);
        for(int i=0; i<n; i++){
            const string food=foods[i], cuisine=cuisines[i];
            const uint64_t f=key(food), c=key(cuisine);
            int rating=ratings[i];
            mp[f]={rating, cuisine};
            Rated[c].insert({rating, food});
        }
    }
    
    void changeRating(const string& food, int newRating) {
        const uint64_t f=key(food); 
        auto [i, cuisine]=mp[f];
        const uint64_t c=key(cuisine);
        Rated[c].erase({i, food});
        Rated[c].insert({newRating, food});
        mp[f]={newRating, cuisine};
    }
    
    string highestRated(const string& cuisine) {
        return Rated[key(cuisine)].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
 auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();