class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        numsHash = set(nums)

        if len(nums) > len(numsHash):
            return True
        else:
            return False