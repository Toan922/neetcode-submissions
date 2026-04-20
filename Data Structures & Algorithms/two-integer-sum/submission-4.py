class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seenSet = {}

        for index, num in enumerate(nums):
            complement = target - num

            if complement in seenSet:
                return [seenSet[complement], index]

            seenSet[num] = index

        return