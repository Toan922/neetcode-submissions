class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # create the list that i am going to return, make it using defaultdict(List) to prevent
        # an error w/ adding to an uninit dict
        grouped = defaultdict(list)

        # loop over the strs list to look at each str individually
        for s in strs:
            # create a dictionary representing the letter count of each str
            count = [0] * 26

            # loop over each char in the str
            for c in s:
                # increment the associated index for the letter
                count[ord(c) - ord('a')] += 1

            # add it to grouped using that count as the key and the word as the value
            # make it a tuple to serve 
            grouped[tuple(count)].append(s)

        # return the values of grouped as a list
        return list(grouped.values())