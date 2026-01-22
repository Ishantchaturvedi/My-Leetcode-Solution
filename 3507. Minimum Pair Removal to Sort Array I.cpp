from typing import List

class Solution:
   def minimumPairRemoval(self, nums: List[int]) -> int:
       arr = nums[:]
       ops = 0

       def sorted_check(a):
           return all(a[i] >= a[i-1] for i in range(1, len(a)))

       while not sorted_check(arr):
           min_sum = float('inf')
           idx = 0
           for i in range(len(arr)-1):
               s = arr[i] + arr[i+1]
               if s < min_sum:
                   min_sum = s
                   idx = i
           arr[idx] = min_sum
           arr.pop(idx+1)
           ops += 1

       return ops