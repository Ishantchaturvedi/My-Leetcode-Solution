class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;
        for (int num : nums1) {
            if (num == 0) z1++;
            else s1 += num;
        }
        for (int num : nums2) {
            if (num == 0) z2++;
            else s2 += num;
        }
        long long base1 = s1 + z1;
        long long base2 = s2 + z2;
        if (base1 == base2) return base1;
        long long diff = abs(base1 - base2);
        if (base1 < base2) {
            if (z1 == 0) return -1;
            return base2;
        }
        else {
            if (z2 == 0) return -1;
            return base1;
        }
    }
};