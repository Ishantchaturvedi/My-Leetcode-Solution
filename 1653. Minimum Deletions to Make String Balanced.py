class Solution:
    def minimumDeletions(self, s: str) -> int:
        cntA, ans=0, 0
        for i in range(len(s)-1, -1, -1):
            if s[i]=='a': cntA+=1
            else: ans=min(ans+1, cntA)
        return ans
        