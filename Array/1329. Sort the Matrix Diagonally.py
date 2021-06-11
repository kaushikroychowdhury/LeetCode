class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        xl, yl = len(mat), len(mat[0])
        t = [ [] for i in range( xl+yl ) ]
        
        for i in range(xl):
            for j in range(yl):
                t[i - j].append(mat[i][j])
                
        for l in t:
            l.sort(reverse=True)


        for i in range(xl):
            for j in range(yl):
                mat[i][j] = t[i-j].pop()
                
        return mat