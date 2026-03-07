# Count all i,j pairs where i<j and abs(b[i]-b[j]) = k [k>=0]
from collections import defaultdict

def solve():
    n,k=map(int,input().split())
    b=list(map(int,input().split()))
    cnt=0
    hashMap={}

    for i in range(n):
        # abs(b[i]-b[j]) = k 
        # b[i]-b[j] = -k or b[i]-b[j] = k
        # b[j] = b[i]+k or b[j] = b[i]-k
        if b[i]+k in hashMap:
            cnt+=hashMap[b[i]+k]
        if k != 0 and b[i]-k in hashMap: # k zero hone par double cnt hoga
            cnt+=hashMap[b[i]-k]
    
        if b[i] in hashMap:
            hashMap[b[i]]+=1
        else:
            hashMap[b[i]]=1

    print(cnt)

solve()

    