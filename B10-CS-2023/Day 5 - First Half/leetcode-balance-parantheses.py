leetcode remove-k-digits

[{()(){[]}}]

[{({)}}]

[ { ( { 

HOW TO SOLVE A PROBLEM:
1. Recognise the I/P and O/P and required information (Understand the problem)
2. Find the solution mathematically (Never think of any coding/language)
3. Write the Algo
4. Write the pseucode
5. Code it

1. read the string of brackets
2. take a empty stack, sp = -1
3. for each ch in the string:
	if open_bracket:
		sp++ push it on to the stack
	else:
		if ch is ')' and stk[sp] is ')':
			pop()
		elif ch is '}' and stk[sp] is '{':
			pop()
		elif ch is ']' and stk[sp] is '[':
			pop()
		else:
		arranged = false
		break the loop
if arranged and sp == -1:
	print: properly arrange
		

((()()))
arranged = true
oc = 0
cc = 0
for bracket in brackets:
	if bracket is '(':
		oc++
	else:
		cc++
	if cc > oc:
		arranged = false
		break // break the loop
if arranged and oc == cc:

