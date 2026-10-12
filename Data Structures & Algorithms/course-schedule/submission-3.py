class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        crs_mp = {i:[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            crs_mp[crs].append(pre)

        seen = set()

        def dfs(crs):
            if crs in seen:
                return False

            if crs_mp[crs] == []:
                return True

            seen.add(crs)

            for pre in crs_mp[crs]:
                if not dfs(pre):
                    return False

            seen.remove(crs)
            crs_mp[crs] = []
            return True

        for c in range(numCourses):
            if not dfs(c):
                return False

        return True

