class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # def empty hash map representing the seen nums
        seen = {}

        # iterate over list using index and num via enum
        for index, num in enumerate(nums):
            # calc the complement
            complement = target - num

            # if the complement has been seen
            if complement in seen:
                # return its index (has to have been before) and the current index
                return [seen[complement], index]
            
            # otherwise add current num to seen
            seen[num] = index
