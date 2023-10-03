def solution(t):    
    m, n, p = map(int, input().split())
    lst = []
    for i in range(m):
        lst.append(list(map(int, input().split())))
    
    steps = 0
    for i in range(n):
        max = lst[p-1][i]
        for j in range(m):
            if max < lst[j][i]:
                max = lst[j][i]
        steps = steps + max - lst[p-1][i]
    
    print("case #{0}: {1}".format(t+1, steps))

test = int(input())
for x in range(test):
    solution(x)
