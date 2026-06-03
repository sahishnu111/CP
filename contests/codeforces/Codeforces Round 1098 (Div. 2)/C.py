import sys

def solve():
    INPUT = sys.stdin.read().split()
    if not INPUT:
        return
    test = int(INPUT[0])
    idx=1

    out=[]

    for _ in range(test):
        a= int(INPUT[idx])
        n= int(INPUT[idx+1])
        b1= int(INPUT[idx+2])
        b2= int(INPUT[idx+3])
        idx+=4

        if b1 > b2:
            b1, b2 = b2, b1
        
        d1=str(b1)
        d2=str(b2)
        s=str(a)
        l=len(s)
        ans=float('inf')

        def correct(x):
            nonlocal ans
            if not x:
                return
            val = int(x)
            ans= min(ans, abs(val-a))
        



        #smaller 
        if l>1:
            correct(d2*(l-1))
        # larger
        correct(d1*(l+1))

        for i in range(l+1):
            pref = ""
            found=True

            for j in range(i):
                if s[j] == d1 or s[j] == d2:
                    pref+=s[j]
                else:
                    found = False
                    break
            
            if not found:
                continue

            if i==l:
                correct(pref)
                continue
            
            #branch

            if d1 < s[i]:
                correct(pref+d1+d2*(l-i-1))
            if d2 < s[i]:
                correct(pref+d2+d2*(l-i-1))
            if d1 > s[i]:
                correct(pref+d1+d1*(l-i-1))
            if d2 > s[i]:
                correct(pref+d2+d1*(l-i-1))
        out.append(str(ans))

    sys.stdout.write('\n'.join(out) + '\n')


if __name__ == "__main__":
    solve()


    