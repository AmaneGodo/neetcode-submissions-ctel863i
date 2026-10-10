class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows = len(heights)
        cols = len(heights[0])
        atl = set()
        pac = set()
        res = []

        def dfs(r, c, visited, prevHeight):
            if (r not in range(rows) or
                c not in range(cols) or
                (r, c) in visited or
                heights[r][c] < prevHeight):
                    return

            visited.add((r, c))
            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

            for dr, dc in directions:
                if (r + dr in range(rows) and
                    c + dc in range(cols)):
                        dfs(r + dr, c + dc, visited, heights[r][c])

        for r in range(rows):
            dfs(r, 0, pac, heights[r][0])
            dfs(r, cols - 1, atl, heights[r][cols - 1])

        for c in range(cols):
            dfs(0, c, pac, heights[0][c])
            dfs(rows - 1, c, atl, heights[rows - 1][c])

        for r in range(rows):
            for c in range(cols):
                if (r, c) in pac and (r, c) in atl:
                    res.append([r, c])

        return res