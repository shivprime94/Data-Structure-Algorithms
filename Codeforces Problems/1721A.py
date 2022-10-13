def solution(li):
    more = [li.count(li[0]), li.count(li[1]), li.count(li[2]), li.count(li[3])]
    if 4 in more:
        return 0
    elif 3 in more:
        return 1
    elif 2 in more and 1 not in more:
        return 1
    elif 2 in more and 1 in more:
        return 2
    elif 1 in more:
        return 3
 
t = int(input())
for i in range(t):
    li = []
    a,b = str(input())
    c,d = str(input())
    li.append(a)
    li.append(b)
    li.append(c)
    li.append(d)
    ans = solution(li)
    print(ans)
