class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:

        arr = [0] * (len(nums) + 1)
        
        for left, rght in queries:
            arr[left  ]+= 1
            arr[rght+1]-= 1

        return all(num <= acc for num, acc in zip(nums, accumulate(arr))) 