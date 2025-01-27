class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> dagAdjacencyList(numCourses);
        for(const auto &edge: prerequisites) {
            dagAdjacencyList[edge[0]].push_back(edge[1]);
        }
        vector<unordered_set<int>> descendantsOf(numCourses);
        vector<bool> visited(numCourses, false);
        function<void(int)> computeDescendantsOf = [&](const int &course) {
            if(visited[course]) {
                return;
            }
            visited[course] = true;
            for(const auto &nextCourse: dagAdjacencyList[course]) {
                computeDescendantsOf(nextCourse);
                descendantsOf[course].insert(nextCourse);
                descendantsOf[course].insert(descendantsOf[nextCourse].begin(), descendantsOf[nextCourse].end());
            }
        };
        for(int course = 0; course < numCourses; course++) {
            computeDescendantsOf(course);
        }
        // cout << descendantsOf << endl;
        vector<bool> queryReplies;
        for(const auto &query: queries) {
            queryReplies.push_back(descendantsOf[query[0]].find(query[1]) != descendantsOf[query[0]].end());
        }
        return queryReplies;

        // O(n^2+q) time
        // O(n^2) space
    }
};