class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []
        count = 0
        for char in s:
            if char == '(':
                stack.append('(')
                count += 1
            elif not stack:
                count += 1
            else:
                stack.pop()
                count -= 1
        return count