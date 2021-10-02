try:
    t = int(input())
    for i in range(t):
        a = int(input())
        b = str(a)
        b_length = len(b)
        slice_String = b[::-1]
        print(int(slice_String))

except:
    pass