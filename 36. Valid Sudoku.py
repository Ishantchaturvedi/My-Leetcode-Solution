class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row, col, cell = [0] * 9, [0] * 9, [0] * 9
        for i, j in product(range(9), repeat = 2):
            if board[i][j] != '.':
                mask = 1 << int(board[i][j])
                k = (i // 3) * 3 + j // 3
                if mask & row[i] or mask & col[j] or mask & cell[k]:
                    return False
                row[i] |= mask
                col[j] |= mask
                cell[k] |= mask
        return True