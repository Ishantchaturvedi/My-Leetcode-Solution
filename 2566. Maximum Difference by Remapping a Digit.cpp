class Solution {
public:
    int minMaxDifference(int num) {
        std::string s = std::to_string(num);
        char firstNon9 = 0, firstNon0 = 0;

        for (char c : s) {
            if (firstNon9 == 0 && c >= '0' && c <= '8') firstNon9 = c;
            if (firstNon0 == 0 && c >= '1' && c <= '9') firstNon0 = c;
        }

        std::string maxStr = s, minStr = s;
        if (firstNon9) {
            for (char &c : maxStr)
                if (c == firstNon9) c = '9';
        }
        if (firstNon0) {
            for (char &c : minStr)
                if (c == firstNon0) c = '0';
        }

        return std::stoi(maxStr) - std::stoi(minStr);
    }
};