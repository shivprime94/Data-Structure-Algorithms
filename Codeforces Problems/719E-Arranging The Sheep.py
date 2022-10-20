for _ in range(int(input())):
    n=int(input())
    arr=input()
    left=[0]*n
    c=0
    idx=-1
    for i in arr:
        idx+=1
        if i=="*":
            c+=1
            left[idx]=left[idx-1]
        else:
            left[idx]+=left[idx-1]+c
    right=[0]*(n+1)
    c=0
    for i in range(n-1,-1,-1):
        if arr[i]=="*":
            c+=1
            right[i]+=right[i+1]
        else:
            right[i]+=right[i+1]+c
    ans=float("inf")
    for i in range(n):
        if arr[i]==".":
            ans=min(ans,left[i]+right[i+1])
            if i-1>-1:
                ans=min(ans,left[i-1]+right[i])
    print(ans if ans!=float("inf") else 0)  