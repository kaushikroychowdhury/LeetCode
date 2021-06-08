class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        third = 0
        tup = set(nums)
        l = list(tup)
        l.sort(reverse = True)
        if len(l) == 1:
            return l[0]
        elif len(l) == 2:
            return l[0]
        else:
            return l[2]
        