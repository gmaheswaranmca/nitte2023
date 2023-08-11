history =['']
doc = history[-1]
Q=int(input())
for I in range(Q):
    QT = input()
    if '1' == QT[0]:
        text = QT[2:]
        doc += text
        print(f'[doc:{doc}]')
        history.append(doc)
        print(f'[his:{history}]')
    elif '2' == QT[0]:
        k = int(QT[2:])
        doc = doc[:len(doc)-k]
        print(f'[doc:{doc}]')
        history.append(doc)
        print(f'[his:{history}]')
    elif '3' == QT[0]:
        k = int(QT[2:])
        print(doc[k-1])
    elif '4' == QT[0]:
        history.pop()
        doc = history[-1]
        print(f'[doc:{doc}]')
        print(f'[his:{history}]')
        
