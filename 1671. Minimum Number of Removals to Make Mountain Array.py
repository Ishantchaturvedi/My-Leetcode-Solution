from typing import List

class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [1] * n
        suffix = [1] * n
        dp = [nums[0]]

        # Binary search helper function
        def binary_search(arr, target):
            l, r = 0, len(arr) - 1
            while l <= r:
                mid = (l + r) // 2
                if arr[mid] == target:
                    return mid
                elif arr[mid] < target:
                    l = mid + 1
                else:
                    r = mid - 1
            return l

        # Compute prefix (LIS up to each index)
        for i in range(1, n):
            if dp[-1] < nums[i]:
                dp.append(nums[i])
                prefix[i] = len(dp)
            else:
                idx = binary_search(dp, nums[i])
                dp[idx] = nums[i]
                prefix[i] = idx + 1

        # Reset dp and calculate suffix (LIS from each index to the end)
        dp = [nums[-1]]
        for i in range(n - 2, -1, -1):
            if dp[-1] < nums[i]:
                dp.append(nums[i])
                suffix[i] = len(dp)
            else:
                idx = binary_search(dp, nums[i])
                dp[idx] = nums[i]
                suffix[i] = idx + 1

        # Calculate minimum removals for mountain array
        ans = n + 1
        for i in range(1, n - 1):
            if prefix[i] != 1 and suffix[i] != 1:  # Valid peak
                count = n - (prefix[i] + suffix[i] - 1)
                ans = min(count, ans)

        return ans