class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        mx = 0
        cnt = 0

        for num in nums : 
            if num == 1:
                cnt += 1
            else :
                cnt = 0
            
            mx = max(mx,cnt)
        
        return mx
        