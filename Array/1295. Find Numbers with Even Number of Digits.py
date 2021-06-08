class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        output = 0
        for i in nums:
            count = 0
            j = i
            while j > 0:
                j =  j // 10
                count += 1
            
            if count % 2 == 0 :
                output +=1
                
        return output