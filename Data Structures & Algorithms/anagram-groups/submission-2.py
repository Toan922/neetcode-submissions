class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # declare grouped as defaultdict(list) to avoid issues of list init
        grouped = defaultdict(list)

        # iterate over the list of strs
        for s in strs:
            # create a array of size 26 representing the alphabet
            alphabet_key = [0] * 26

            # iterate over the characters in the string s
            for c in s:
                # for each character, increment the count of its occurence in alphabet_key
                alphabet_key[ord(c) - ord('a')] += 1
            
            # append the string s to the associated alphabet key
            # make the key a tuple since tuples are immutable and keys need to be immutable
            grouped[tuple(alphabet_key)].append(s)

        # return the values of the grouped dict as a list so its a list of lists
        return list(grouped.values())