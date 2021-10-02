try:
    tc = int(input())
    prime = False
    for i in range(tc):
        
        p = int(input())
        if p > 1:
            for i in range(2,p):
                if p%i ==0:
                    prime = True
                    break

        if prime:
            print("no")
        else:
            print("yes")


except:
    pass