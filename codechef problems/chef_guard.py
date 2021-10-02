try:
    T = int(input())
    for i in range(T):
        A, B = map(int, input().split(' '))
        c = max(A, B)
        d = A+B
        print(c, end = " ")
        print(d)

except:
    pass