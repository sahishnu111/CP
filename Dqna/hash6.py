def solve():
    #Find count of number of subarrays with sum ==  k
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    pSum=0
    hashMap={}
    cnt=0
    for i in range(n):
        pSum+=a[i]
        if pSum-k in hashMap:
            cnt+=hashMap[pSum-k]
        
        if pSum in hashMap:
            hashMap[pSum]+=1
        else:
            hashMap[pSum]=1
    print(cnt)

solve()