try:
    t = int(input())
    a = []
    for i in range(t):
        b = int(input())
        a.append(b)

    a.sort()
    
    for j in range(len(a)):
        print(a[j])
except:
    pass