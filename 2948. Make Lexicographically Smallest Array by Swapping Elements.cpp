class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int size = nums.size();
        vector<pair<int, int>> valueIndexPairs(size);
        for (int index = 0; index < size; index++) {
            valueIndexPairs[index] = {nums[index], index};
        }
        sort(valueIndexPairs.begin(), valueIndexPairs.end());
        vector<int> indexSequence;
        indexSequence.push_back(valueIndexPairs[0].second);
        int previousPartitionStart = 0;
        for (int currentIndex = 1; currentIndex < size; currentIndex++) {
            if (abs(valueIndexPairs[currentIndex].first - valueIndexPairs[currentIndex - 1].first) <= limit) {
                indexSequence.push_back(valueIndexPairs[currentIndex].second);
            } else {
                sort(indexSequence.begin() + previousPartitionStart, indexSequence.end());
                previousPartitionStart = currentIndex;
                indexSequence.push_back(valueIndexPairs[currentIndex].second);
            }
        }
        sort(indexSequence.begin() + previousPartitionStart, indexSequence.end());
        for (int index = 0; index < size; index++) {
            nums[indexSequence[index]] = valueIndexPairs[index].first;
        }
        return nums;
    }
};