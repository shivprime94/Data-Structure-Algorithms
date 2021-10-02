try:
    x = int(input())
    y = float(input())
    
    if x%5==0 and x>0 and y>0 and y>x:
    	print(y-x-0.50)
    else:
    	print(y)
except:
    pass