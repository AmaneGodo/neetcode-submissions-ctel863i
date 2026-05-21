class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        cur = []

        def dfs(n_open, n_closed):
            if n_open == n == n_closed:
                res.append(''.join(cur.copy()))
                return 

            if n > n_open:
                cur.append('(')
                dfs(n_open + 1, n_closed)
                cur.pop()

            if n_open > n_closed:
                cur.append(')')
                dfs(n_open, n_closed + 1)
                cur.pop()

        dfs(0, 0)
        return res