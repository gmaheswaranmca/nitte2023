class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        digits = []
        for I in range(len(num)-1):
            if (int(num[I]) > int(num[I+1])) and k>0:
                k-=1
                continue
            digits.append(num[I])
            if I == len(num)-1-1:
                digits.append(num[I+1])
        rnum = ''.join(digits)
        if rnum == '':
            rnum = '0'
        return str(int(rnum))