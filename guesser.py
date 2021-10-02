from random import randrange
n = randrange(1000)
while True:
    v = int(input())
    if v == n:
        print('you Win!')
        break
    print('Smaller' if (n<v) else 'Bigger')