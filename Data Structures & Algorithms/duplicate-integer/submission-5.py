class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # init an empty set
        hashSet = set()

        # iterate over the list
        for num in nums:
            # if the current index is in set then duplicate -> return T
            if num in hashSet:
                return True
            # otherwise append current index to set
            hashSet.add(num)

        # at the end return F
        
        return False