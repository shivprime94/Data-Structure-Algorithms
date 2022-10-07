try:
	n = int(input())	
	for i in range(n):
		A,B = map(int, input().split(' '))
		answer = A + B
		print(answer)
except:
	pass
