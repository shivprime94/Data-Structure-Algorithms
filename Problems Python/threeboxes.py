T = int(input())

for i in range(0, T):
    A, B, C, D = map(int, input().split())

    while(D > 0):
        if (D - A - B - C) >= 0:
            print(1)
            D = 0
        elif (D - A - B) >= 0 or (D - A - C) >= 0 or (D - B - C) >= 0:
            print(2)
            D = 0
        else:
            print(3)
            D = 0
