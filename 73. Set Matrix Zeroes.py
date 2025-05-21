class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m=len(matrix)
        n=len(matrix[0])
        val=[]
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==0:
                    val.append([i,j])
        for v in val:
            i=v[0]
            j=v[1]
            for k in range(m):
                matrix[k][j]=0
            for l in range(n):
                matrix[i][l]=0
        return matrix
        