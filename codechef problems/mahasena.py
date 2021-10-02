try:
    sol = int(input())
    A = input()
    weapons = A.split(" ")
    odd = 0
    even = 0
    for i in weapons:
        if int(i)%2 ==0:
            even = even + 1
        elif int(i)%2 == 1:
            odd = odd + 1
    
    if even > odd:
        print("READY FOR BATTLE")
    else:
        print("NOT READY")


except:
    pass