uint32_t offline[100] = {0};

class Solution {
public:
    static vector<int> countMentions(const int n, vector<vector<string>>& a) noexcept {
        vector<int> users(n, 0);
        int all = 0;
        sort(a.begin(), a.end(), [](const vector<string>& x, const vector<string>& y) {
            int tx = stoi(x[1]);
            int ty = stoi(y[1]);
            if (tx != ty) return tx < ty;
            if ('O' == x[0][0]) return true;
            return false;
        });
        for (int i = 0; i < a.size(); ++i) {
            const auto& e = a[i];
            if ('O' == e[0][0]) { // "OFFLINE", "timestamp", "id"]
                offline[stoi(e[2])] = 60 + stoi(e[1]);
            } else { // ["MESSAGE", "timestamp", "mentions_string"]
                const auto& s = e[2];
                if ('A' == s[0]) {
                    ++all;
                    continue;
                }
                if ('H' == s[0]) {
                    const int t = stoi(e[1]);
                    for (int id = 0; id < n; ++id) {
                        if (t >= offline[id]) ++users[id];
                    }
                    continue;
                }
                for (int j = 2; j < s.size() - 1; j += 4) { // "id0 id1 ... id99"
                    int id = s[j] - '0';
                    if (' ' != s[j + 1]) id = 10 * id + (s[++j] - '0');
                    ++users[id];
                }
                if ('d' == s[s.size() - 2]) ++users[s[s.size() - 1] - '0'];
            }
        }
        for (int i = 0; i < n; ++i) {
            users[i] += all;
        }
        memset(offline, 0, sizeof(offline));
        return users;
    }
};