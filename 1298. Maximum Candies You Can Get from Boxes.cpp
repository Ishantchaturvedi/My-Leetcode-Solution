class Solution {
public:
    int maxCandies(std::vector<int>& status, std::vector<int>& candies, std::vector<std::vector<int>>& keys, std::vector<std::vector<int>>& containedBoxes, std::vector<int>& initialBoxes) {
        std::queue<int> queue;
        for (int box : initialBoxes) queue.push(box);
        
        int total = 0;

        while (!queue.empty()) {
            int box = queue.front();
            queue.pop();

            if (status[box] == 0) {
                if (queue.empty()) return total;
                queue.push(box);
            } else {
                total += candies[box];

                for (int key : keys[box]) {
                    status[key] = 1;
                }

                for (int contained : containedBoxes[box]) {
                    queue.push(contained);
                }
            }
        }

        return total;
    }
};