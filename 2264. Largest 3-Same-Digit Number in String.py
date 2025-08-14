class Solution:
    def largestGoodInteger(self, num: str) -> str:
        count = 0
        current = None
        max_digit = -1
        for char in num:
            if char == current:
                count += 1
                if count == 3 and int(current) > max_digit:
                    max_digit = int(current)
            else:
                current = char
                count = 1
        return "" if max_digit < 0 else str(max_digit) * 3
