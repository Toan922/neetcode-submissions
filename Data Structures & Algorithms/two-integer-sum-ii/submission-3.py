class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # init a l and r pointer as start of list and end of list
        l, r = 0, len(numbers) - 1

        # loop while left is less than right
        while l < r:
            # calc the sum as numbers[l] + numbers[r]
            num = numbers[l] + numbers[r]

            # if the indices are correct -> return left and right + 1
            # + 1 since it is 1-indexed not 0-indexed
            if num == target:
                return [l + 1, r + 1]
            # if the sum is < target then left is too small -> increment left
            # this is because it is a sorted list
            elif num < target:
                l += 1
            # otherwise sum is > target then right is too large -> decrement right
            else:
                r -= 1