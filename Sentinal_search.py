print("Sentinel search...")
rno=[1,2,3,4,5,62,17,30]
print(rno)
len=len(rno)
print(len)

key=30
last=rno[len-1]   #To store last element in the last variable
rno[len-1]=key    
print(last)
print(rno)

i=0
while(rno[i]!=key): #while condition is true go on searching next element in rno and once false comes out
    i=i+1
    
rno[len-1]=last    #store the last variable value to its original position so that it gets checked
if((i<len-1) or (key==rno[len-1])):  #check if i is in the scope of list
    print("Key found at location : ",i)
else:
    print("Key not found")