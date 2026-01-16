class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        maxL=0
        seen=set()
        def findLen(fences, calM):
            nonlocal maxL
            fences.sort()
            for x, y in combinations(fences, 2):
                Len=y-x
                if calM: 
                    if Len>maxL and Len in seen:
                        maxL=Len
                else:
                    seen.add(Len) 
        hz, vz=len(hFences)+2, len(vFences)+2
        if hz>vz:
            return self.maximizeSquareArea(n, m, vFences, hFences)
        hFences+=[1, m]
        vFences+=[1, n]
        findLen(hFences, False)
        findLen(vFences, True)
        return -1 if maxL==0 else maxL*maxL%(10**9+7)
        