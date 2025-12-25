#!/usr/bin/env python3
# ========================= IMPORTS =========================
import sys
import math
from collections import defaultdict, deque, Counter
from itertools import combinations, permutations, accumulate
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop, heapify
from functools import lru_cache, reduce
from typing import List, Tuple, Set, Dict

# ========================= FAST I/O =========================
input = sys.stdin.readline

def read_int():
    return int(input())

def read_ints():
    return map(int, input().split())

def read_int_list():
    return list(map(int, input().split()))

def read_str():
    return input().strip()

def read_str_list():
    return input().strip().split()

# ========================= CONSTANTS =========================
MOD = 10**9 + 7
MOD2 = 998244353
INF = float('inf')
NINF = float('-inf')
PI = math.pi

# ========================= UTILITY FUNCTIONS =========================

def gcd(a, b):
    """Greatest Common Divisor"""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Least Common Multiple"""
    return a * b // gcd(a, b)

def power(a, b, m=MOD):
    """Fast exponentiation: (a^b) % m"""
    res = 1
    a %= m
    while b > 0:
        if b & 1:
            res = (res * a) % m
        a = (a * a) % m
        b >>= 1
    return res

def mod_inv(a, m=MOD):
    """Modular multiplicative inverse using Fermat's little theorem"""
    return power(a, m - 2, m)

def is_prime(n):
    """Check if n is prime"""
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def sieve(n):
    """Sieve of Eratosthenes - returns list of primes up to n"""
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    return [i for i in range(n + 1) if is_prime[i]]

def prime_factors(n):
    """Get prime factorization of n"""
    factors = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            factors.append(d)
            n //= d
        d += 1
    if n > 1:
        factors.append(n)
    return factors

def binary_search(arr, target):
    """Binary search - returns index or -1"""
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

# ========================= DEBUG =========================
DEBUG = False

def debug(*args):
    """Print debug information"""
    if DEBUG:
        print("[DEBUG]", *args, file=sys.stderr)

# ========================= SOLUTION =========================

def solve():
    """Main solution function"""
    # Your code here
    pass

# ========================= MAIN =========================

def main():
    """Main function"""
    test = 1
    test = read_int()
    
    for tc in range(1, test + 1):
        # print(f"Case #{tc}:", end=" ")
        solve()

if __name__ == "__main__":
    main()

"""
========================= NOTES =========================
- Python is slower than C++, so optimize when needed
- Use PyPy for faster execution (especially for loops)
- Be careful with integer division: // (floor division) vs / (true division)
- For large inputs, use sys.stdin.readline instead of input()
- For recursion, increase limit: sys.setrecursionlimit(10**6)
- For floating point: use math.isclose() for comparisons

========================= COMMON PATTERNS =========================
1. Prefix/Suffix Arrays: list(accumulate(arr))
2. Two Pointers: while left < right
3. Sliding Window: deque for optimal performance
4. Binary Search: bisect_left, bisect_right
5. DFS/BFS: use deque for BFS
6. Dynamic Programming: @lru_cache for memoization
7. Counter for frequency counting
8. defaultdict for default values

========================= TIME COMPLEXITIES =========================
Same as C++, but Python is ~10x slower:
- O(n log n): ~10^5 operations
- O(n): ~10^7 operations
- O(n^2): ~10^3 operations
Use PyPy for better performance!

========================= QUICK SNIPPETS =========================

# Read n integers into list
n = read_int()
arr = read_int_list()

# Read 2D matrix
matrix = []
for _ in range(n):
    row = read_int_list()
    matrix.append(row)

# Prefix Sum
pref = [0] * (n + 1)
for i in range(1, n + 1):
    pref[i] = pref[i-1] + arr[i-1]
# Or use: pref = list(accumulate([0] + arr))

# Prefix XOR
pref = [0] * (n + 1)
for i in range(1, n + 1):
    pref[i] = pref[i-1] ^ arr[i-1]

# Frequency Counter
freq = Counter(arr)
# freq[x] gives count of x

# Default Dict
from collections import defaultdict
d = defaultdict(int)  # default value 0
d = defaultdict(list)  # default value []

# Binary Search on answer
left, right = 0, 10**9
ans = -1
while left <= right:
    mid = (left + right) // 2
    if check(mid):
        ans = mid
        right = mid - 1
    else:
        left = mid + 1

# DFS (recursion)
def dfs(node, visited):
    visited.add(node)
    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs(neighbor, visited)

# BFS
from collections import deque
def bfs(start):
    queue = deque([start])
    visited = {start}
    while queue:
        node = queue.popleft()
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Dynamic Programming with memoization
from functools import lru_cache
@lru_cache(maxsize=None)
def dp(n):
    if n <= 1:
        return 1
    return dp(n-1) + dp(n-2)

# Sort with custom key
arr.sort(key=lambda x: x[0])  # sort by first element
arr.sort(key=lambda x: (x[0], -x[1]))  # sort by first asc, second desc

# Matrix rotation (90° clockwise)
matrix = list(zip(*matrix[::-1]))

# Get all divisors of n
def get_divisors(n):
    divisors = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
    return sorted(divisors)

========================= END =========================
"""
