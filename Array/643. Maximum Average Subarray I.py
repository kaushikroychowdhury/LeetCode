class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        if len(nums) <= k: return sum(nums) / k
        curr_res, glob_res = sum(nums[:k]), sum(nums[:k])
        l = 0
        for r in range(k, len(nums)):
            curr_res = curr_res - nums[l] + nums[r]
            glob_res = max(glob_res, curr_res)
            l += 1
        return glob_res / k