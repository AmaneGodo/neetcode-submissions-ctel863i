class Solution:
    def isValid(self, s: str) -> bool:
        co_map = {')':'(', ']':'[', '}':'{'}

        stack = []

        for c in s:
            if stack and c in co_map:
                if co_map[c] == stack[-1]:
                    stack.pop()

                else:
                    return False

            else:
                stack.append(c)

        return stack == []