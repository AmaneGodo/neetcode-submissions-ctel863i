class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)

        for s in strs:
            track = [0] * 26

            for c in s:
                track[ord(c) - ord('a')] += 1


            mp[tuple(track)].append(s)

        return list(mp.values())
