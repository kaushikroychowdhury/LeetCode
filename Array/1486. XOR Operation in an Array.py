class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        output = start
        for i in range(1,n):
            output = output ^ start + 2*i
        return output