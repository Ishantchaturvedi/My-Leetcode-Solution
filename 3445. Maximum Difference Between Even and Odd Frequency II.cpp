class Solution {
public:
    int maxDifference(string s, int k) {

        vector<char> validDig = {'0', '1', '2', '3', '4'};
        vector<vector<int>> prefixCnts = vector(validDig.size(), vector(s.length() + 1, 0));
        vector<vector<int>> nextIndex = vector(validDig.size(), vector(0, 0));
        vector<int> freq(validDig.size());
        int ans = INT_MIN;

        for(int i = 0; i < s.length(); i++) {
            for(int j = 0; j < validDig.size(); j++) {
                prefixCnts[j][i + 1] = prefixCnts[j][i];
            }
            prefixCnts[s[i] - '0'][i + 1]++;
            nextIndex[s[i] - '0'].push_back(i);
            freq[s[i] - '0']++;
        }

        for(char a : validDig) {
            if(freq[a - '0'] - 2 < ans) {
                continue;
            }

            for(char b : validDig) {
                if(a == b || freq[b - '0'] < 2) {
                    continue;
                }
                else {
                    ans = max(ans, maxDifferenceSub(prefixCnts[a - '0'], prefixCnts[b - '0'], nextIndex[b - '0'], k));
                }
            }
        }

        return ans;
    }

    int maxDifferenceSub(vector<int>& a, vector<int>& b, vector<int>& nextB, int k) {
        vector<vector<vector<int>>> maxAfter = vector(a.size(), vector(2, vector(2, INT_MIN)));
        int ans = INT_MIN;

        maxAfter[a.size() - 1][a[a.size() - 1] & 1][b[b.size() - 1] & 1] = a[a.size() - 1] - b[b.size() - 1];
        for(int idx = a.size() - 2; idx >= 0; idx--) {
            maxAfter[idx][0][0] = maxAfter[idx + 1][0][0];
            maxAfter[idx][1][0] = maxAfter[idx + 1][1][0];
            maxAfter[idx][0][1] = maxAfter[idx + 1][0][1];
            maxAfter[idx][1][1] = maxAfter[idx + 1][1][1];

            maxAfter[idx][a[idx] & 1][b[idx] & 1] = max(
                maxAfter[idx + 1][a[idx] & 1][b[idx] & 1],
                a[idx] - b[idx]
            );
        }

        
        int idx = 0;
        int next = nextB[idx++];

        for(int i = 0; i < a.size() - 1; i++) {
            if(i == next) {
                if(idx == nextB.size()) {
                    break;
                }
                else {
                    next = nextB[idx++];
                }
            }

            int smallestJ = max(k + i - 1, next);
            if(smallestJ > a.size() - 2) {
                break;
            }

            int bestOption = maxAfter[smallestJ + 1][!(a[i] & 1)][b[i] & 1];

            if(bestOption == INT_MIN) {
                continue;
            }

            ans = max(ans, b[i] - a[i] + bestOption);
        }

        return ans;
    } 
};