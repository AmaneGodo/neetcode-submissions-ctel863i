class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows = len(grid)
        cols = len(grid[0])
        visited = set()
        res = 0

        def bfs(r, c):
            q = collections.deque()
            q.append((r, c))
            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
            visited.add((r, c))

            while q:
                row, col = q.popleft()

                for d in directions:
                    if (
                        row + d[0] in range(rows) and
                        col + d[1] in range(cols) and
                        (row + d[0], col + d[1]) not in visited and
                        grid[row + d[0]][col + d[1]] == "1"):

                        visited.add((row + d[0], col + d[1]))
                        q.append((row + d[0], col + d[1]))

        for r in range(rows):
            for c in range(cols):
                if ((r, c) not in visited) and grid[r][c] == "1":
                    bfs(r, c)
                    res += 1

        return res
