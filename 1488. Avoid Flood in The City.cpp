class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lake;
        set<int> dryDays;
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                result[i] = 1;
            } else {
                result[i] = -1;
                if (lake.count(rains[i])) {
                    auto it = dryDays.lower_bound(lake[rains[i]]);
                    if (it == dryDays.end()) return {};
                    result[*it] = rains[i];
                    dryDays.erase(it);
                }
                lake[rains[i]] = i;
            }
        }
        return result;
    }
};