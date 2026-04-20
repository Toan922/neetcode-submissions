class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # init an empty dict representing seen numbers
        seenSet = {}

        # iterate over list using enum to get both num and index
        for index, num in enumerate(nums):
            # calc the complement using target num - current num
            complement = target - num

            # if complement has been seen then return
            if complement in seenSet:
                # returns the index of the complement and current index
                return [seenSet[complement], index]

            # otherwise add the current num and its index to seenSet
            seenSet[num] = index

        return