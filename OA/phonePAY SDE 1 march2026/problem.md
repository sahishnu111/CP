# Maximize Even-Sum Subarrays with One Swap

## Problem Statement

You are given an array `A` of `N` integers. Define **M** as the number of contiguous subarrays whose sum is **even**.

You are allowed to perform **at most one operation**: pick any index `i` (1-indexed) and replace `A[i]` with **any integer you choose**.

Your goal is to **maximize M** after performing at most one such operation.

Output the **maximum possible value of M**.

---

## Input Format

```
Line 1: A single integer N
Line 2: N space-separated integers A[1], A[2], ..., A[N]
```

---

## Output Format

```
Print a single integer — the maximum value of M achievable
```

---

## Constraints

```
1 ≤ N ≤ 10^5
-10^9 ≤ A[i] ≤ 10^9
```

---

## Background / Definitions

- A subarray is defined by a pair of indices `(l, r)` with `1 ≤ l ≤ r ≤ N`
- The sum of a subarray `A[l..r]` is `A[l] + A[l+1] + ... + A[r]`
- A sum is **even** if it is divisible by 2
- The total number of subarrays of an array of size N is `N*(N+1)/2`
- You may choose **not** to perform the operation if M is already maximal

---

## Example Test Cases

### Test Case 1 — Basic

**Input:**
```
4
1 2 3 4
```

**Output:**
```
6
```

**Explanation:**

Original array `[1, 2, 3, 4]`:

All subarrays and their sums:

| Subarray | Sum | Even? |
|----------|-----|-------|
| [1] | 1 | ❌ |
| [2] | 2 | ✅ |
| [3] | 3 | ❌ |
| [4] | 4 | ✅ |
| [1,2] | 3 | ❌ |
| [2,3] | 5 | ❌ |
| [3,4] | 7 | ❌ |
| [1,2,3] | 6 | ✅ |
| [2,3,4] | 9 | ❌ |
| [1,2,3,4] | 10 | ✅ |

Current M = 4. By changing `A[1] = 1` to any even number (say `2`), array becomes `[2, 2, 3, 4]` — recompute to verify maximum M = **6**.

---

### Test Case 2 — No Operation Needed

**Input:**
```
4
2 4 6 8
```

**Output:**
```
10
```

**Explanation:**
All elements are even. Every subarray sum is even. Total subarrays = `4*5/2 = 10`. No operation needed. Answer = **10**.

---

### Test Case 3 — Single Element

**Input:**
```
1
3
```

**Output:**
```
1
```

**Explanation:**
Change `A[1] = 3` to any even number. The only subarray `[A[1]]` then has even sum. M = **1**.

---

### Test Case 4 — All Odd Elements

**Input:**
```
5
1 3 5 7 9
```

**Output:**
```
6
```

**Explanation:**
Original array — subarrays with even sum only arise from pairs of odd numbers:

| Subarray | Even? |
|----------|-------|
| [1,3] | ✅ |
| [3,5] | ✅ |
| [5,7] | ✅ |
| [7,9] | ✅ |
| [1,3,5,7] | ✅ |
| [3,5,7,9] | ✅ |

Current M = 6. Try changing the best index and verify if M can increase further. Expected answer = **6**.

> ✏️ **Note to candidate:** Check all indices to see if any single change improves M.

---

### Test Case 5 — Alternating Parity

**Input:**
```
6
1 2 1 2 1 2
```

**Output:**
```
9
```

> ✏️ **Note to candidate:** Compute M for the original array first, then determine the optimal index to change.

---

### Test Case 6 — Key Stress Test (Large N Pattern)

**Input:**
```
8
3 1 4 1 5 9 2 6
```

**Output:**
```
?
```

> ✏️ **Note to candidate:** This is a self-verification test. Run your O(N) or O(N log N) solution and cross-check against a brute-force O(N²) solution on this input. Both must agree.

---

### Test Case 7 — All Same Odd

**Input:**
```
3
7 7 7
```

**Output:**
```
3
```

**Explanation:**
Total subarrays = 6. Currently even-sum subarrays: `[7,7]`, `[7,7]` = 2. Changing optimal index to an even number — verify that M = **3** is achievable.

---

### Test Case 8 — Two Elements

**Input:**
```
2
1 1
```

**Output:**
```
3
```

**Explanation:**
Change either element from odd to even. Then array is `[2, 1]` or `[1, 2]`:
- `[2]` → even ✅
- `[1]` → odd ❌
- `[2,1]` → odd ❌

Hmm, try `[2, 2]`:
- `[2]` ✅, `[2]` ✅, `[2,2]` ✅ → M = **3** ✅

Since you can set `A[i]` to **any** value, changing one element to match the parity of the other is optimal.

---

## Follow-Up Questions

- Can you solve this in **O(N)** time?
- What if you are allowed **at most K operations** instead of one?
- What if instead of maximizing even-sum subarrays, you want to **minimize** them?
- What if the replacement value must come from **within the array itself** (i.e. you can only swap two elements)?
- How does your approach change if subarrays are replaced by **subsequences**?

---

## Hints (Unfold only if stuck)

> **Hint 1:** Think about prefix sum parities. How does flipping the parity of a single element affect prefix parities at positions to its right?

> **Hint 2:** If you change the parity of `A[i]`, how many prefix parities change, and what is the net effect on M?

> **Hint 3:** Can you precompute for each index `i` what the gain/loss in M would be if you flip the parity of `A[i]`? Can this be done in O(1) per index after O(N) preprocessing?

---

## Tags

`Arrays` `Prefix Sum` `Parity` `Greedy` `Counting`
`PhonePe Interview` `SDE1` `F2F Round` `OA Style`