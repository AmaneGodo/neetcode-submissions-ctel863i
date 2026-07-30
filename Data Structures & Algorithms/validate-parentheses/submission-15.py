class Solution:
    def isValid(self, s: str) -> bool:
        mp = {')':'(', 
              ']':'[',
              '}':'{'}

        stack = []

        for p in s:
            if p in mp:
                if stack and stack[-1] == mp[p]:
                    stack.pop()

                else:
                    return False

            else:
                stack.append(p)

        return stack == []