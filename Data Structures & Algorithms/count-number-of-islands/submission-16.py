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
            visited.add((r, c))
            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

            while q:
                row, col = q.popleft()

                for dr, dc in directions:
                    if (row + dr in range(rows) and
                        col + dc in range(cols) and
                        (row + dr, col + dc) not in visited and
                        grid[row + dr][col + dc] == "1"):

                        visited.add((row + dr, col + dc))
                        q.append((row + dr, col + dc))

        for r in range(rows):
            for c in range(cols):
                if (r, c) not in visited and grid[r][c] == "1":
                    bfs(r, c)
                    res += 1

        return res