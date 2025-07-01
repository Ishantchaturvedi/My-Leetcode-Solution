class Solution:
    def possibleStringCount(self,s: str) -> int:
        s=s[::-1]
        c=0
        k=s[0]
        for i in range(len(s)) :
            if s[i]==k:
                c+=1
            if s[i]!=k:
                k=s[i]
        return c