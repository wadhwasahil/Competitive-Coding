class Solution:    
        
    def decodeString(self, s: str) -> str:
        stack = []
        i = 0
        while i < len(s):
            if s[i].isdigit():
                temp = s[i]
                i = i + 1
                while s[i].isdigit():
                    temp += s[i]
                    i = i + 1
                i = i - 1
                stack.append(int(temp))
            elif s[i].isalpha():
                if len(stack):
                    top = stack.pop()
                    if top.isalpha():
                        stack.append(top + s[i])
                    else:
                        stack.append(top)
                        stack.append(s[i])
                else:
                    stack.append(s[i])
            elif s[i] == "[":
                stack.append(s[i])
            elif s[i] == "]":
                top = stack.pop()
                while top != "[":
                    top_2 = stack.pop()
                    if top_2.isalpha():
                        top = top_2 + top
                        stack.append(top)
                        break
                    else:
                        stack.append("[")
                        stack.append(top)
                        break
                top = stack.pop()
                stack.pop()
                k = stack.pop()
                stack.append(top * k)
                
            i = i + 1
        return ("".join(stack))
                
                    
