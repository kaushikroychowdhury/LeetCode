class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        l = list()
        # l1 = nums[0:n]
        # l2 = nums[n:len(nums)]
        
        # for i,j in zip(l1,l2): 
        #     l.append(i)
        #     l.append(j)
        for i in range(0,n):
            l.append(nums[i])
            l.append(nums[i+n])
        return l