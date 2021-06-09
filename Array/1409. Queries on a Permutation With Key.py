class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        p = [i for i in range(1,m+1)]
        sol=[]
        
        n = len(queries)
        for i in range(n):
            pos = p.index(queries[i])
            sol.append(pos)
            p.insert(0, p.pop(pos))
            
        return sol