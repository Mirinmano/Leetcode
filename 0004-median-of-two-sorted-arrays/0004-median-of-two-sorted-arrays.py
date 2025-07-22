class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        l = nums1+nums2
        l.sort()
        if len(l)%2==0:
            i=len(l)//2
            return (l[i]+l[i-1])/2
        else :
            return l[len(l)//2]