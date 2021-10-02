try:
    n=int(input())
    for i in range(1,n+1):
        s=[]
        a,b,c=map(int,input().split())
        s.append(a)
        s.append(b)
        s.append(c)
        s.sort()
        print(s[1])
     

except:
    pass