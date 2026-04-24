class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # def a count dict
        count = {}

        # def a count ticker/frequency list
        freq = [[] for i in range(len(nums) + 1)]

        # loop through the nums list
        for n in nums:
            # count the # of occurences for that num -> get count + 1
            # this is saying get the current count of n, if no n, init to 0
            count[n] = 1 + count.get(n, 0)

        # loop through the freq list
        for n, c in count.items():
            # append the num n to the associated count c
            freq[c].append(n)

        # create a results list to store return
        res = []

        # iterate from the top down of freq, start = end of freq, stop = first index, step = -1
        for i in range(len(freq) - 1, 0, -1):
            # for each box, append each entry into res until it hits k
            for n in freq[i]:
                res.append(n)
                if len(res) == k:
                    return res