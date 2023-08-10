import sys
class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        sys.set_int_max_str_digits(0)
        if k == len(num):
            return "0"
        digits = []
        for e in num:
            while len(digits) > 0 and e < digits[-1] and k > 0:
                k-=1
                digits.pop()
            digits.append(e)#push
        while digits and k>0:
            digits.pop()
            k-=1
        
        rnum = ''.join(digits)
        
        while rnum and rnum[0]=='0':#remove leading zeroes
            rnum = rnum[1:]
        if rnum == '':
            rnum = '0'
        return rnum#str(int(rnum))