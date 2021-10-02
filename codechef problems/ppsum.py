try:
    t = int(input())
    while t>0:
        d, n = map(int, input().split())
        for i in range(1,d+1):
            n = (n*(n+1))/2


        print(int(n))
        t = t-1

except:
    pass