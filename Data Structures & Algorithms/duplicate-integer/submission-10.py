class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # init an empty list representing seenNums
        seenNums = set()

        # iterate over nums
        for num in nums:
            # if num has been seen return True
            if num in seenNums:
                return True
            
            # otherwise add num to seenNums
            seenNums.add(num)
        
        # once fully through if no dupe then return false
        return False