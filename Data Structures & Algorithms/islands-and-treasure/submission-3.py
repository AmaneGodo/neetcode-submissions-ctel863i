class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS = len(grid)
        COLS = len(grid[0])
        visited = set()
        q = collections.deque()

        def addGrid(r, c):
            if (
                r not in range(ROWS) or
                c not in range(COLS) or
                (r, c) in visited or
                grid[r][c] == -1
            ):
                return 

            visited.add((r, c))
            q.append((r, c))

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 0:
                    visited.add((r, c))
                    q.append((r, c))

        dist = 0
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

        while q:
            for _ in range(len(q)):
                r, c = q.popleft()

                grid[r][c] = dist

                for dr, dc in directions:
                    addGrid(r + dr, c + dc)

            dist += 1
