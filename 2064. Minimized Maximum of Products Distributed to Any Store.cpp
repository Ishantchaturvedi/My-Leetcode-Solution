class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 1, r = 100000;
        while (l < r){
            int mid = (l + r) / 2;
            if (canDistribute(mid, n, quantities))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
private:
    bool canDistribute(int k, int stores, vector<int>& quantities){
        for (int quantity : quantities){
            int neededStores = quantity / k + (quantity % k != 0);
            if ((stores -= neededStores) < 0) return false;
        }
        return true;
    }
};