class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []

        for i, t in enumerate(nums):
            # if not the first index and the num to the left = current num -> go next
            if i > 0 and t == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1

            while l < r:
                threesum = t + nums[l] + nums[r]

                if threesum > 0:
                    r -= 1
                elif threesum < 0:
                    l += 1
                else:
                    res.append([t, nums[l], nums[r]])
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1

        return res
                