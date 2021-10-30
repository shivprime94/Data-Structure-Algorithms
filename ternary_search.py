def accept_array(A):
    n = int(input("enter total no: "))
    print("input roll no in sorted")
    for i in range(n):
        x = int(input("enter rlno of std %d : " % (i + 1)))
        A.append(x)
    print(" info accepted \n", A)
    return n
# A = []
# accept_array(A)

def display_array(A, n):
    if (n == 0):
        print(" \n no records in data")
    else:
        print("array : ", end='')
        for i in range(n):
            print("%d  " % A[i], end='')

        print("\n")
# n = []
# display_array(A,n)

def ternary_search(A, l, r, key):
    l = 0
    r = len(A) - 1
    while (r >= l):
        mid1 = l + ((r - l) // 3)
        mid2 = r - ((r - l) // 3)
        if (A[mid1] == key):
            return mid1
        if (A[mid2] == key):
            return mid2
        if (key < A[mid1]):
            # l = 0
            # r = mid1 - 1
            return ternary_search(A, l, mid1 - 1, key)
        elif (key > A[mid2]):
            # l = mid2 + 1
            # r = len(A) - 1
             return ternary_search(A, mid2 + 1, r, key)
        else:
            # l = mid1 + 1
            # r = mid2 - 1
             return ternary_search(A, mid1 + 1, mid2 - 1, key)
    return -1


def main():
    A = []
    while True:
        print("\t accept info of std ")
        print("\tternary search")
        print(" \texit")

        ch = int(input("enter ur choice: "))
        if (ch == 3):
            print("end ")
            quit()

        elif (ch == 1):
            A = []
            n = accept_array(A)
            display_array(A, n)
        elif (ch == 2):
            x = int(input("enter no to be search:"))
            flag = ternary_search(A, 0, len(A) - 1, x)
            if (flag == -1):
                print("\t%d  rl isn't mem of club \n" % x)
            else:
                print("\t%d rl is mem of this sorted at pos %d"%(x, flag + 1))
        else:
            print(" wrong choice do gain")

main()