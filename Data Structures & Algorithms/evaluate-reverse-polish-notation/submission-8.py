class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        res = 0

        for c in tokens:
            if c == "+":
                a, b = stack.pop(), stack.pop()
                res = b + a
                stack.append(res)

            elif c == "-":
                a, b = stack.pop(), stack.pop()
                res = b - a
                stack.append(res)

            elif c == "*":
                a, b = stack.pop(), stack.pop()
                res = b * a 
                stack.append(res)

            elif c == "/":
                a, b = stack.pop(), stack.pop()
                res = int(b / a)
                stack.append(res)

            else:
                stack.append(int(c))


        return stack[-1]
