class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        l = len(nums)
        goodPairs = 0
        for i in range(0,l):
            for j in range(i+1,l):
                if nums[i] == nums[j]:
                    goodPairs +=1
        return goodPairs