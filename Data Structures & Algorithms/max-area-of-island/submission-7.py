class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        rows = len(grid)
        cols = len(grid[0])
        maxArea = 0

        def bfs(r, c):
            q = collections.deque()
            q.append((r, c))
            grid[r][c] = 0
            area = 1

            while q:
                directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
                r, c = q.popleft()

                for dr, dc in directions:
                    if (
                        (r + dr) in range(rows) and
                        (c + dc) in range(cols) and 
                        grid[r + dr][c + dc] == 1):

                        area += 1
                        q.append((r + dr, c + dc))
                        grid[r + dr][c + dc] = 0

            return area

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    maxArea = max(maxArea, bfs(r, c))

        return maxArea

