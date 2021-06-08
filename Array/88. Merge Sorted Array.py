class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if m == 1 and n == 0: return nums1
        c = 0
        for i in range(m, m+n):
            nums1[i] = nums2[c]
            c += 1
        nums1.sort()