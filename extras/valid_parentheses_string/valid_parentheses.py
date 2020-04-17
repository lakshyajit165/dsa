#!/usr/bin/env python3
class Solution:
    def checkValidString(self, s: str) -> bool:
        stack, star_stack = [], []
        for index, char in enumerate(s):
            if char == '(':
                stack.append(index)
            elif char == '*':
                star_stack.append(index)
            elif char == ')':
                if(len(stack) > 0):
                    stack.pop()
                elif(len(star_stack) > 0):
                    star_stack.pop()
                else:
                    return False
        
        while stack and star_stack:
            if stack[-1] < star_stack[-1]:
                stack.pop()
                star_stack.pop()
            else:
                break
        return len(stack) == 0

s = input()
print(Solution.checkValidString(Solution(), s))