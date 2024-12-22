#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<pair<int, int>>& queries) {
        int n = heights.size();
        vector<vector<int>> st(n, vector<int>(20));
        vector<int> log(n + 1);

        log[0] = -1;
        for (int i = 1; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }

        for (int i = 0; i < n; i++) {
            st[i][0] = heights[i];
        }

        for (int j = 1; j < 20; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int l = q.first, r = q.second;
            if (l > r) swap(l, r);

            int j = log[r - l + 1];
            res.push_back(max(st[l][j], st[r - (1 << j) + 1][j]));
        }

        return res;
    }
};