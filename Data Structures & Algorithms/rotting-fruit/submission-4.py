class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        q = deque()
        fresh = 0
        time = 0

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    q.append((r, c))

                if grid[r][c] == 1:
                    fresh += 1

        if fresh == 0:
            return 0

        while q and fresh > 0:
            for _ in range(len(q)):
                row, col = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in directions:
                    nxt_r, nxt_c = row + dr, col + dc

                    if (
                        nxt_r in range(rows) and
                        nxt_c in range(cols) and
                        grid[nxt_r][nxt_c] == 1
                        ):
                            grid[nxt_r][nxt_c] = 2
                            q.append((nxt_r, nxt_c))
                            fresh -= 1

            time += 1

        return time if fresh <= 0 else -1
