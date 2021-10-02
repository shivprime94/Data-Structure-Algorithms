try:
    tc = int(input())
    for i in range(tc):
        ch = input()
        if ch == 'B' or ch == 'b':
            print('BattleShip')
        elif ch =='C' or ch == 'c':
            print('Cruiser')
        elif ch == 'D' or ch == 'd':
            print('Destroyer')
        elif ch == 'F' or ch == 'f':
            print('Frigate')

except:
    pass