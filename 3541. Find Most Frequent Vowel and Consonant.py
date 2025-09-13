from collections import Counter
class Solution:
    def maxFreqSum(self, s: str) -> int:
        vow='aeiou'
        s=Counter(s)
        cnt1,cnt2=0,0
        for k,v in s.items():
            if k in vow:cnt1=max(cnt1,v)
            else:cnt2=max(cnt2,v)
        return cnt1+cnt2