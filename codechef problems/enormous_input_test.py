try:
	n, k = map(int, input().split(' '))
	ans = 0
	for i in range(0,n):
		c = int(input())
		i+=1
		if c%k == 0:
			ans += 1
	print(ans)
except:
	pass