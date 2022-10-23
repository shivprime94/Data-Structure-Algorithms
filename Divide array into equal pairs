# Determine if an array can be divided into pairs such that the sum of elements
# in each pair is divisible by the given integer `k`
def findPairs(arr, k):
 
    # base case: input contains an odd number of elements
    # (an odd number of elements cannot be paired)
    if len(arr) & 1:
        return 0
 
    # create a boolean array to mark elements that formed a pair
    visited = [0] * len(arr)
 
    # consider each element as the first element of a pair
    for i in range(len(arr) - 1):
 
        # ignore the current element if it is already part of another pair
        if visited[i]:
            continue
 
        # find the first non-visited element `arr[j]` that forms a pair with `arr[i]`
        j = i + 1
        while j < len(arr):
            if not visited[j] and (arr[j] + arr[i]) % k == 0:
                # pair found `(arr[i], arr[j])`
                visited[j] = 1
                break
            j += 1
 
        # return 0 if pair not found for the current element
        if j == len(arr):
            return 0
 
    # we reach here only when each element forms a pair
    return 1
 
 
if __name__ == '__main__':
 
    arr = [2, 9, 4, 1, 3, 5]
    k = 6
 
    if findPairs(arr, k):
        print("Pairs can be formed")
    else:
        print("Pairs cannot be formed")
