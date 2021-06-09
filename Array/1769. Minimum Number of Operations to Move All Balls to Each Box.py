class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        box = []
        box[:0]=boxes
        
        n = len(box)
        boxes_contain_ball = []
        sol = []
        
        for i in range(n):
            if box[i] == '1':
                boxes_contain_ball.append(i)

        for i in range(n):
            sum = 0
            for j in boxes_contain_ball:
                sum += abs((j+1) - (i+1))
            sol.append(sum)
            
        return sol
        