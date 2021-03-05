# https://leetcode.com/problems/integer-to-roman/submissions/

class Solution:
    def getElement(self, num, value, symbol):
        coefficient = num // value
        if coefficient:
            return [coefficient * value, coefficient * symbol]
        return None
    
    
    def intToRoman(self, num: int) -> str:
        value = [1000, 500, 100, 50, 10, 5, 1]
        symbol = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
        romans = ''
        for i in range(len(value)):
            element = self.getElement(num, value[i], symbol[i])
            if element:
                num -= element[0]
                romans += element[1]
            if i + 1 < len(value) and value[i] // value[i + 1] == 5:
                element = self.getElement(num, value[i] - value[i + 1], symbol[i + 1] + symbol[i])
                if element:
                    num -= element[0]
                    romans += element[1]
            if i + 2 < len(value) and value[i] // value[i + 2] == 10:
                element = self.getElement(num, value[i] - value[i + 2], symbol[i + 2] + symbol[i])
                if element:
                    num -= element[0]
                    romans += element[1]
        return romans
