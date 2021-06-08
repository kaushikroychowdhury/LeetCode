class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        def sol(p1, p2):
            x = p2[0] - p1[0]
            y = p2[1] - p1[1]
        
            if x == 0 and y == 0:
                return 0
            if x == 0:
                return abs(y)
            elif y == 0 or x == y:
                return abs(x)
            else:
                return min(abs(x), abs(y)) + abs(abs(x)-abs(y))
            
            
        n = len(points)
        path = 0
        for i in range(n-1):
            j = i+1
            
            path += sol(points[i], points[j])
            
        return path