class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        count_s1 = [0] * 26
        count_s2 = [0] * 26

        for i in range(len(s1)):
            count_s1[ord(s1[i].lower()) - ord('a')] += 1
            count_s2[ord(s2[i].lower()) - ord('a')] += 1

        if count_s1 == count_s2:
            return True

        l = 0
        for j in range(len(s1), len(s2)):
            count_s2[ord(s2[j].lower()) - ord('a')] += 1
            count_s2[ord(s2[l].lower()) - ord('a')] -= 1
            l += 1

            if count_s1 == count_s2:
                return True

        return False 