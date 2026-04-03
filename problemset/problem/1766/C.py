import sys

sys.setrecursionlimit(200005)

def solve():
    # Read m and the two rows
    try:
        line = sys.stdin.readline()
        if not line:
            return
        m = int(line.strip())
        grid = [sys.stdin.readline().strip() for _ in range(2)]
    except ValueError:
        return
    
    def check(startRow):
        curr=startRow

        for col in range(m):
            if grid[curr][col]=='W':
                return False
            other = 1-curr
            if grid[other][col]=='B':
                curr=other
            
            if col+1<m:
                if grid[curr][col+1]=='W':
                    return False
        return True
    
    ans=False
    if grid[0][0]=='B' and check(0):
        ans=True
    elif grid[1][0]=='B' and check(1):
        ans=True
    
    print("YES" if ans else "NO")


def main():
    line = sys.stdin.readline()
    if line:
        t = int(line.strip())
        for _ in range(t):
            solve()

if __name__ == '__main__':
    main()
                    