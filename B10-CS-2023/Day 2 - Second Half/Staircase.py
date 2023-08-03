'''
   #  1  3spaces 1star    (N-I)sp I*
  ##  2  2spaces 2stars
 ###  3  1space  3stars
####  4  0space  4stars
N=4
'''
N=int(input())
for I in range(1,N+1):
    print(' ' * (N-I), '*' * I, sep='')