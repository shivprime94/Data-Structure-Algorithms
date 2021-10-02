try:
    T= int(input())
    for i in range(T):
        p = int(input())
        price = [2048,1024,512,256,128,64,32,16,8,4,2,1]
        s = 0
        while p>0:
            for i in price:
                if p>=i:
                    s = s +p//i
                    p = p%i
        print(s)


except:
    pass