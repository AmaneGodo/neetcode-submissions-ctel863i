class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        part = []

        def bt(start):
            if start >= len(s):
                res.append(part[:])
                return 

            for end in range(start + 1, len(s) + 1):
                piece = s[start:end]
                if piece == piece[::-1]:
                    part.append(piece)
                    bt(end)
                    part.pop()

        bt(0)
        return res