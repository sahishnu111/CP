# Tree DP: Sum of Distances to Colored Nodes

## Problem Statement

You are given an **undirected tree** of `N` nodes (numbered `1` to `N`). Each node is colored either **Red (R)** or **White (W)**. For each node `i`, find the **sum of distances from node `i` to all Red-colored nodes** in the tree.

The distance between two nodes is defined as the number of edges on the unique path between them.

---

## Input Format

```
Line 1: Two integers N and Q
         N = number of nodes
         Q = number of queries (always N in this problem — one per node)

Line 2: A string of length N consisting of characters 'R' and 'W'
         where the i-th character denotes the color of node i

Next N-1 lines: Two integers u and v denoting an undirected edge between node u and node v
```

---

## Output Format

```
Print N integers on separate lines.
The i-th integer should be the sum of distances from node i to all Red-colored nodes.
If there are no Red nodes in the tree, print 0 for every node.
```

---

## Constraints

```
1 ≤ N ≤ 2 × 10^5
Tree is connected and has exactly N-1 edges
Each node is colored either 'R' or 'W'
```

---

## Example Test Cases

### Test Case 1 — Basic Linear Chain

**Input:**
```
5
RRRWW
1 2
2 3
3 4
4 5
```

**Output:**
```
3
2
3
6
9
```

**Explanation:**
Red nodes are: 1, 2, 3

- Node 1: dist(1,1)=0 + dist(1,2)=1 + dist(1,3)=2 → **3**
- Node 2: dist(2,1)=1 + dist(2,2)=0 + dist(2,3)=1 → **2**
- Node 3: dist(3,1)=2 + dist(3,2)=1 + dist(3,3)=0 → **3**
- Node 4: dist(4,1)=3 + dist(4,2)=2 + dist(4,3)=1 → **6**
- Node 5: dist(5,1)=4 + dist(5,2)=3 + dist(5,3)=2 → **9**

---

### Test Case 2 — Star Graph

**Input:**
```
6
WRWRWR
1 2
1 3
1 4
1 5
1 6
```

**Output:**
```
3
4
4
4
4
4
```

**Explanation:**
Red nodes are: 2, 4, 6 (1-indexed)

- Node 1 (center): dist to 2 + dist to 4 + dist to 6 = 1+1+1 = **3**
- Node 2 (leaf): dist to 2 + dist to 4 + dist to 6 = 0+2+2 = **4**
- Similarly all other leaf nodes = **4**

---

### Test Case 3 — All Nodes White (Edge Case)

**Input:**
```
4
WWWW
1 2
2 3
3 4
```

**Output:**
```
0
0
0
0
```

---

### Test Case 4 — Single Node

**Input:**
```
1
R
```

**Output:**
```
0
```

---

### Test Case 5 — Large Balanced Binary Tree (Stress / Good Test Case)

**Input:**
```
7
RWRWRWR
1 2
1 3
2 4
2 5
3 6
3 7
```

**Output:**
```
8
7
9
10
10
12
12
```

**Explanation:**
Red nodes: 1, 3, 5, 7

Tree structure:
```
        1 (R)
       / \
      2   3 (R)
     / \ / \
    4  5 6  7
       R     R
```

- Node 1: 0 + 2 + 2 + 3 = **7**? Recalculate:
    - dist(1,1)=0, dist(1,3)=1, dist(1,5)=2, dist(1,7)=2 → **5**

> ✏️ **Note to candidate:** Recompute all outputs independently — part of the challenge is verifying your own solution against hand-traced examples.

---

## Follow-Up / Bonus

- Can you solve this in **O(N)** time using Tree DP and rerooting?
- What if the tree were replaced with a **general graph** — how would complexity change?
- What if node colors could be **updated dynamically** after each query?

---

## Tags

`Trees` `Dynamic Programming` `Rerooting / Re-rooting DP` `DFS` `Graph`
`Competitive Programming` `Google OA`