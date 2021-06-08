class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        l = list()
        count = 0
        for i in nums:
            for j in nums:
                if j != i and j < i:
                    count += 1
            l.append(count)
            count = 0
        return l