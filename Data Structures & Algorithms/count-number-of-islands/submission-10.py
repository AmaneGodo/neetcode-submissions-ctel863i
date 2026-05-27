class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        ROWS = len(grid)
        COLS = len(grid[0])
        visited = set()
        count = 0

        def bfs(r, c):
            q = collections.deque()
            visited.add((r, c))
            q.append((r, c))

            while q:
                row, col = q.popleft()
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

                for dr, dc in directions:
                    if (
                        row + dr in range(ROWS) and
                        col + dc in range(COLS) and
                        grid[row + dr][col + dc] == "1" and
                        (row + dr, col + dc) not in visited
                    ):
                        visited.add((row + dr, col + dc))
                        q.append((row + dr, col + dc))


        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == "1" and (r, c) not in visited:
                    bfs(r, c)
                    count += 1
        
        return count
