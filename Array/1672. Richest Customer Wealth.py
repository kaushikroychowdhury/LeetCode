class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        rich, s = 0,0
        for i in accounts:
            for j in i:
                s = s + j
            if s > rich:
                rich = s
            s = 0
        return rich