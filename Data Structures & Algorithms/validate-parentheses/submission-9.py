class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        cToO_map = {')' : '(', ']':'[', '}' : '{'}

        for c in s:
            if c in cToO_map:
                if stack and stack[-1] == cToO_map[c]:
                    stack.pop()

                else:
                    return False

            else:
                stack.append(c)

        return True if not stack else False