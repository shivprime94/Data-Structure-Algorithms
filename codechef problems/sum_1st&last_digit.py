try:
    tc = int(input())
    for i in range(tc):
        n = int(input())
        length = len(str(n))
        first = n//(10**(length-1))
        last = n%10
        
        print(first + last)
    
except:
    pass