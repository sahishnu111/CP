def solve():
    n,l,r = map(int,input().split())
    a = [1,7,2,5,2,6,7,4,2]
    prefix_sum = [0]*(n+1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i]+a[i]
    
    print(prefix_sum[r]-prefix_sum[l-1])
solve()
