try:
    l = []
    for i in range(int(input())):
        c = input()
        for i in c:
            l.append(i)
        if l == l[: : -1]:
            print('wins')
        else:
            print('loses')
        l = []

except:
    pass