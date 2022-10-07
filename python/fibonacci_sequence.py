# fibonacci series
# 0, 1, 1, 2, 3, 5, 8, ...

n = int(input("No. of terms? "))

n_1, n_2 = 0, 1
counter = 0

if n <= 0:
    print("Please input a positive integer value")
elif n == 1:
    print("Fibonacci series ", n, ":")
    print(n_1)
else:
    print("Fibonacci sequence:")
    while counter < n:
        print(n_1)
        n_f = n_1 + n_2
        n_1 = n_2
        n_2 = n_f
        counter += 1
