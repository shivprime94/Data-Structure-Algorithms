try:
    n = int(input())
    p1 = 0
    p2 = 0
    lead = 0
    l = 0 
    plr = 0
    win = 0
    for i in range(0,n):
        a,b = input().split(' ')
        p1+=int(a)
        p2+=int(b)
        if (p1>p2):
            lead = p1 - p2
            plr = 1
        else:
            lead = p2 - p1
            plr = 2
        if (lead>1):
            l=lead
            win = plr
    print(win,end = " ")
    print(l)
except:
    pass