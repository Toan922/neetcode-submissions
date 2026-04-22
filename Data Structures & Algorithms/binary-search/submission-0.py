class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # def a left and right pointer, left = start of list, right = end of list
        left, right = 0, len(nums) - 1

        # while left is <= right continue the loop, left is not past right yet
        while left <= right:
            # calc the middle pointer as the int avg (using //) of left and right
            middle = (left + right) // 2

            # if the number at the middle index is > target, make right = 1 less than middle
            if nums[middle] > target:
                right = middle - 1
            # if the number at the middle index is < target, make left = 1 over middle
            elif nums[middle] < target:
                left = middle + 1
            # if neither, then the target is at the middle pointer -> return middle
            else:
                return middle

        # if nothing was found, return -1
        return -1

        