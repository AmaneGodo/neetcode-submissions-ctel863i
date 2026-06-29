class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mp = {')':'(', ']':'[', '}':'{'}

        for c in s:
            if c in mp:
                if stack and mp[c] == stack[-1]:
                    stack.pop()

                else:
                    return False

            else:
                stack.append(c)

        return stack == []
