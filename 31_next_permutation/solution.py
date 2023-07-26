from typing import List
from math import inf


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        N = len(nums)
        req_idx = -1
        for i in range(N - 1):
            if nums[i] < nums[i + 1]:
                req_idx = i
                break
        """
        If the break point is not found.
        It is the last element in the permutation
        """
        if req_idx == -1:
            nums.sort()

        next_max_idx, smallest_diff = -1, inf
        for i in range(req_idx + 1, N):
            if (nums[req_idx] < nums[i]) and (
                (nums[i] - nums[req_idx]) < smallest_diff
            ):
                next_max_idx = i
                smallest_diff = nums[i] - nums[req_idx]

        nums[req_idx], nums[next_max_idx] = nums[next_max_idx], nums[req_idx]
        nums[req_idx + 1 :] = sorted(nums[req_idx + 1 :])


nums = [3, 2, 1]
print(nums)
solution_obj = Solution().nextPermutation(nums=nums)
print(nums)
