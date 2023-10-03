import numpy

n,m = input().split()
arr = input().split()

arr1 = numpy.array(arr)
arr1.reshape(arr,(int(n),int(m)))

print(arr1)