class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        l = list()
        i = 0
        c = len(nums)/2
        while i < c:
            freq = nums[2*i]
            val = nums[2*i+1]
            
            for j in range(0,freq):
                l.append(val)
            i += 1
        return l