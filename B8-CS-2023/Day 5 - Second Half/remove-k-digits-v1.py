class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        digits = []
        for I in range(1,len(num)):
            if num[I-1] > num[I] and k > 0:
                k-=1
                continue
            digits.append(num[I-1])
            if I == len(num)-1:
                digits.append(num[I])
        
        
        rnum = ''.join(digits)
        if rnum == '':
            rnum = '0'
        return str(int(rnum))