class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        sub = []

        def bt(openN, closeN):
            if (openN == closeN == n):
                res.append("".join(sub))
                return

            if openN < n:
                sub.append("(")
                bt(openN + 1, closeN)
                sub.pop()

            if openN > closeN:
                sub.append(")")
                bt(openN, closeN + 1)
                sub.pop()

        bt(0, 0)
        return res