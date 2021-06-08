class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        l = list()
        maximum = max(candies)
        for i in candies:
            if i + extraCandies < maximum:
                l.append(False)
                continue
            e = extraCandies
            while e >= 0:
                if i + e == maximum:
                    l.append(True)
                    break
                e = e-1
            if e == -1:
                l.append(False)
        return l