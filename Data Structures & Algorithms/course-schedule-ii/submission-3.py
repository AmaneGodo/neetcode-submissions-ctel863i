class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        crs_map = {i:[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            crs_map[crs].append(pre)

        res = []
        visited = set()
        cycle = set()

        def dfs(crs):
            if crs in cycle:
                return False

            if crs in visited:
                return True

            cycle.add(crs)

            for pre in crs_map[crs]:
                if not dfs(pre):
                    return False

            cycle.remove(crs)
            visited.add(crs)
            res.append(crs)
            return True

        for c in range(numCourses):
            if not dfs(c):
                return []

        return res