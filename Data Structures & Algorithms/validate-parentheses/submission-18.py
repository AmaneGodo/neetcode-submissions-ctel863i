class Solution:
    def isValid(self, s: str) -> bool:
        co_mp = {')':'(', ']':'[', '}':'{'}
        stack = []

        for c in s:
            if stack and c in co_mp:
                if stack[-1] == co_mp[c]:
                    stack.pop()

                else:
                    return False

            else:
                stack.append(c)

        return stack == []