try:
    t = int(input())
    for i in range(t):
        a,b = map(int, input().split())
        if a<1000:
            print(a*b)
        elif a>1000:
            print(a*b - (a*b)*0.1)


except:
    pass