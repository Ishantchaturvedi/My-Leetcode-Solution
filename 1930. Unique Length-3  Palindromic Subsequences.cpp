class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int result = 0;
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c]) continue;

            vector<bool> seen(26, false);
            for (int i = first[c] + 1; i < last[c]; i++) {
                seen[s[i] - 'a'] = true;
            }

            result += count(seen.begin(), seen.end(), true);
        }

        return result;
    }
};