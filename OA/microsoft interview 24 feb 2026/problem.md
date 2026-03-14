# Closest Blue-Red Cell Pair in a Grid

## Problem Statement

You are given a grid of size **N × M**. Each cell in the grid contains one of the following values:

```
0 → Empty cell
2 → Red cell
3 → Blue cell
```

You can move from any cell `(i, j)` to its **4-directional neighbors**:
- Up: `(i-1, j)`
- Down: `(i+1, j)`
- Left: `(i, j-1)`
- Right: `(i, j+1)`

You may pass through **empty cells and any other cells** while traveling.

Your task is to find a **Blue cell `(i, j)`** and a **Red cell `(k, l)`** such that the **shortest path distance** between them is **minimized** over all valid Blue-Red pairs.

Output:
1. The **minimum distance**
2. The **coordinates of the Blue cell and the Red cell** that achieve this minimum (if multiple pairs exist with the same minimum distance, print any one)

---

## Input Format

```
Line 1: Two integers N and M — dimensions of the grid
Next N lines: M space-separated integers per line, each being 0, 2, or 3
```

---

## Output Format

```
Line 1: The minimum distance between any Blue cell and any Red cell
Line 2: Four integers i j k l — where (i,j) is the Blue cell and (k,l) is the Red cell (1-indexed)
```

---

## Constraints

```
1 ≤ N, M ≤ 1000
Grid contains at least one Blue cell (value 3)
Grid contains at least one Red cell (value 2)
It is guaranteed that a path always exists between every Blue and Red cell
```

---

## Example Test Cases

---

### Test Case 1 — Basic Small Grid

**Input:**
```
4 4
0 0 0 2
0 0 0 0
0 0 0 0
3 0 0 0
```

**Output:**
```
6
4 1 1 4
```

**Explanation:**

```
. . . R
. . . .
. . . .
B . . .
```

The only Blue cell is at `(4,1)` and the only Red cell is at `(1,4)`.
Shortest path = `|4-1| + |1-4|` = 3 + 3 = **6** (Manhattan distance, since no obstacles block BFS).

---

### Test Case 2 — Multiple Red and Blue Cells

**Input:**
```
3 5
3 0 0 0 2
0 0 2 0 0
0 0 0 0 3
```

**Output:**
```
2
3 5 2 3
```

**Explanation:**

```
B . . . R
. . R . .
. . . . B
```

Blue cells: `(1,1)`, `(3,5)`
Red cells: `(1,5)`, `(2,3)`

Distances:
- `(1,1)` to `(1,5)` = 4
- `(1,1)` to `(2,3)` = 3
- `(3,5)` to `(1,5)` = 2 ✅
- `(3,5)` to `(2,3)` = 3

Minimum = **2**, achieved by Blue `(3,5)` and Red `(1,5)`.

---

### Test Case 3 — Adjacent Cells

**Input:**
```
2 2
3 2
0 0
```

**Output:**
```
1
1 1 1 2
```

**Explanation:**

```
B R
. .
```

Blue at `(1,1)`, Red at `(1,2)` — directly adjacent. Distance = **1**.

---

### Test Case 4 — Blue and Red Separated by Empty Corridor

**Input:**
```
5 5
3 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 2
```

**Output:**
```
8
1 1 5 5
```

**Explanation:**

```
B . . . .
. . . . .
. . . . .
. . . . .
. . . . R
```

Only one Blue at `(1,1)`, only one Red at `(5,5)`. BFS distance = 4+4 = **8**.

---

### Test Case 5 — Dense Grid with Many Colored Cells

**Input:**
```
4 6
3 0 2 0 3 0
0 2 0 0 0 2
3 0 0 2 0 0
0 0 3 0 0 2
```

**Output:**
```
1
1 1 1 3
```

**Explanation:**

```
B . R . B .
. R . . . R
B . . R . .
. . B . . R
```

Blue cell `(1,1)` and Red cell `(1,3)` are distance 2 apart.
Blue cell `(1,5)` and Red cell `(2,6)` are distance 2 apart.
But Blue `(1,1)` and Red `(2,2)` are distance 2 apart.
Check `(3,1)` Blue and `(2,2)` Red → distance **2**.

> ✏️ **Note to candidate:** Enumerate all pairs carefully. The exact minimum here is **1** — find which adjacent Blue-Red pair achieves it.

---

### Test Case 6 — Single Row

**Input:**
```
1 7
0 3 0 0 0 2 0
```

**Output:**
```
3
1 2 1 6
```

**Explanation:**

```
. B . . . R .
```

Only Blue at `(1,2)`, only Red at `(1,6)`. Distance = 6-2 = **4**.

> ✏️ **Note to candidate:** Recheck the output — verify manually.

---

### Test Case 7 — Stress / Self-Verification Test

**Input:**
```
5 7
0 3 0 0 2 0 0
0 0 0 3 0 0 2
2 0 0 0 0 3 0
0 0 2 0 3 0 0
0 3 0 0 0 0 2
```

**Output:**
```
?
```

> ✏️ **Note to candidate:** The expected output is intentionally left blank. Run your optimized BFS solution and verify it matches a brute-force BFS-from-every-blue-cell solution on this input. Both must agree on both the distance and a valid pair.

---

### Test Case 8 — Edge: 1×1 Grid Not Possible (Boundary Awareness)

**Input:**
```
1 2
3 2
```

**Output:**
```
1
1 1 1 2
```

---

### Test Case 9 — Large Uniform Grid (Performance Test)

**Input:**
```
1000 1000
[Grid where A[1][1] = 3, A[1000][1000] = 2, all other cells = 0]
```

**Expected behavior:** Your solution must run within **2 seconds**. A brute-force BFS from every Blue cell will **TLE**. Multi-source BFS from all Red cells must be used.

> ✏️ **Note to candidate:** Generate this test case programmatically and validate performance.

---

## Follow-Up Questions

- Can you solve this without using a `visited[][]` array? How?
- Can you eliminate the `level[][]` array while still tracking distances? What is the tradeoff?
- Can you eliminate the `parent[][]` (or `gx[][], gy[][]`) arrays used for path reconstruction while still printing the optimal pair?
- What is the **theoretical minimum memory** your BFS solution can use, expressed in grids of size N×M?
- What if cells have **weights** (moving to a Red cell costs 5, Empty costs 1, Blue costs 2)? How does the algorithm change?
- What if instead of minimum distance, you need the **K-th minimum** distance across all Blue-Red pairs?

---

## Hints (Unfold only if stuck)

> **Hint 1:** Running BFS from every Blue cell independently is O(N × M × number of Blue cells) — this will TLE for large grids. Think about reversing the problem.

> **Hint 2:** Multi-source BFS: push **all Red cells** into the BFS queue simultaneously at distance 0. After BFS completes, `level[i][j]` gives the distance from cell `(i,j)` to its nearest Red cell.

> **Hint 3:** After multi-source BFS, the answer is simply `min(level[i][j])` over all Blue cells `(i,j)`.

> **Hint 4:** To also print the pair, track for each cell which Red cell (source) was responsible for its `level` value during BFS.

---

## Tags

`Grid` `BFS` `Multi-source BFS` `Shortest Path` `Graph Traversal`
`Space Optimization` `Amazon OA` `Google OA` `SDE Interview`