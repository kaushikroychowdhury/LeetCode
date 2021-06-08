class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals, key=lambda x: x[0])
        if not intervals or len(intervals) == 1:
            return intervals
        merged=[]
        for i in intervals:
            if not merged or merged[-1][1] < i[0]:
                merged.append(i)
            elif merged[-1][1] > i[0] and merged[-1][1] > i[1]:
                continue
            else:
                merged[-1][1] = i[1]
        
                
        return merged