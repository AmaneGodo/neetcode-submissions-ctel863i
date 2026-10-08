class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        q = deque()

        rows = len(grid)
        cols = len(grid[0])

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r, c))

        while q:
            r, c = q.popleft()
            directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

            for dr, dc in directions:
                nxt_r, nxt_c = r + dr, c + dc

                if (nxt_r in range(rows) and
                    nxt_c in range(cols) and
                    grid[nxt_r][nxt_c] == 2147483647):
                        grid[nxt_r][nxt_c] = grid[r][c] + 1
                        q.append((nxt_r, nxt_c))

        