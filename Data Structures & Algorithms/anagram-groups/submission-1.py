class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        grouped = defaultdict(list)

        for s in strs:
            alphabet_key = [0] * 26

            for c in s:
                alphabet_key[ord(c) - ord('a')] += 1
            
            grouped[tuple(alphabet_key)].append(s)

        return list(grouped.values())