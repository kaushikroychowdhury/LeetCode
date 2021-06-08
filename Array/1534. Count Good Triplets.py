class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        out = 0
        # for i in range(0, len(arr)):
        #     for j in range(i+1, len(arr)):
        #         for k in range(j+1, len(arr)):
        #             u = abs(arr[i] - arr[j])
        #             v = abs(arr[j] - arr[k])
        #             w = abs(arr[i] - arr[k])
        #             if u<=a and v<=b and w<=c:
        #                 out += 1
        
        for i in range(0, len(arr)):
            for j in range(i+1, len(arr)):
                u = abs(arr[i] - arr[j])
                if u <= a:
                    for k in range(j+1, len(arr)):
                    
                        v = abs(arr[j] - arr[k])
                        w = abs(arr[i] - arr[k])
                        if u<=a and v<=b and w<=c:
                            out += 1
                
                        
        return out