class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        
        else:
            tri =[[1], [1,1]]
            for i in range(1,numRows-1):
                Row=[1]
                a = tri[i]
                for j in range(len(a)-1):
                    Row.append(a[j] + a[j+1])
                Row.append(1)
                tri.append(Row)
        return tri