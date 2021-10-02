try:
    t = int(input())
    while t>0:
        a,b = map(int, input().split())
        mul = a*b
        while(b%a!=0):
            r = b%a
            b = a
            a = r
        print(a, mul//a)
        


except:
    pass