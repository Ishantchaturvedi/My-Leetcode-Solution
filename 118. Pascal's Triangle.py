class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [None] * numRows
        for i in range(1, numRows+1):
            curr = [0] * i
            for j in range(i):
                if j == 0 or j == i-1:
                    curr[j] = 1
                else:
                    prev = res[i-2]
                    curr[j] = prev[j-1] + prev[j]
                res[i-1] = curr
        return res    