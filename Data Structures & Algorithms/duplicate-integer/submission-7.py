class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # turn the list into a set
        numsHash = set(nums)

        # if the len of nums is > len of set, there has to be a duplicate
        if len(nums) > len(numsHash):
            return True
        else:
            return False