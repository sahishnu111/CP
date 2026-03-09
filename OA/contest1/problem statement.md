
---

# Question 1: Range Sum Queries

You are given a list of **N numbers** and **Q queries**. Each query is specified by two numbers `i` and `j`.

For every query, return the **sum of numbers in the range `[i, j]` (inclusive)**.

---

# Question 2: Amazon – Security Risk Level

Amazon is launching a security feature that incorporates an advanced antivirus program capable of identifying potential threats among running programs.

The framework manages **`n` active programs**, each having a **Program Identifier (PID)**.

The antivirus program evaluates the **overall security risk** using a specialized algorithm.

---

## Algorithm

The algorithm analyzes **contiguous subarrays** of Program Identifiers (`pid`).

For each subarray:

1. Calculate the **sum of the PIDs**.
2. Divide the sum by a constant **`k`**.
3. Compute the **remainder**.
4. Compare the remainder with the **length of the subarray**.

A subarray is **flagged as malicious** if:

```
Sum(subarray) % k == length(subarray)
```

The **overall security risk** is the **total number of malicious subarrays**.

---

## Function Description

Implement the function:

```
findSecurityLevel(pid, k)
```

### Parameters

* `int pid[n]` — array representing program identifiers
* `int k` — divisor used for remainder calculation

### Returns

* `long` — total count of malicious subarrays

---

## Constraints

```
1 ≤ n ≤ 2 × 10^5
1 ≤ pid[i] ≤ 10^9
1 ≤ k ≤ 10^9
```

---

## Example

### Input

```
n = 4
pid = [1, 3, 2, 4]
k = 4
```

### Analysis

**Subarray [1] (index 0–0)**

```
Sum = 1
Length = 1
1 % 4 = 1
1 == 1  → Malicious
```

**Subarray [2, 4] (index 2–3)**

```
Sum = 6
Length = 2
6 % 4 = 2
2 == 2 → Malicious
```

**Non-malicious example**

Subarray `[3, 2]`

```
Sum = 5
Length = 2
5 % 4 = 1
1 ≠ 2 → Not malicious
```

### Output

```
2
```

---

## Sample Case

### Input

```
n = 5
pid = [1, 4, 2, 3, 5]
k = 100
```

### Output

```
1
```

### Explanation

Only subarray `[1]` satisfies:

```
1 % 100 = 1
length = 1
```

---

# Question 3: Amazon – AWS Load Balancing

AWS dynamically routes traffic to a distributed cluster of **n servers**.

Each server maintains a **connection count**.

The load balancer analyzes **contiguous subarrays of servers** to detect **balanced routing paths**.

---

## Algorithm

For each contiguous subarray:

1. Compute the **sum of connections**.
2. Compute the **remainder when divided by `k`**.
3. Count how many servers have **odd connection counts**.

A subarray is **optimally balanced** if:

```
(sum of connections % k) == number of odd connection servers
```

The **system stability score** equals the **number of such balanced subarrays**.

---

## Function Description

```
findBalancedRouting(connections, k)
```

### Parameters

* `int connections[n]` — server connection counts
* `int k` — calibration factor

### Returns

* `long` — total number of optimally balanced subarrays

---

## Constraints

```
1 ≤ n ≤ 2 × 10^5
1 ≤ connections[i] ≤ 10^9
1 ≤ k ≤ 10^9
```

---

## Sample Case

### Input

```
n = 5
connections = [2, 3, 1, 4, 5]
k = 3
```

### Output

```
2
```

### Explanation

**Subarray [1]**

```
Sum = 1
1 % 3 = 1
Odd servers = 1
Valid
```

**Subarray [3,1,4]**

```
Sum = 8
8 % 3 = 2
Odd servers = 2
Valid
```

---

## Complex Test Case

### Input

```
n = 6
connections = [4, 7, 2, 5, 8, 3]
k = 4
```

### Output

```
3
```

### Explanation

Valid segments:

```
[7,2]        → Sum=9  → 9%4=1 → odd=1
[5]          → Sum=5  → 5%4=1 → odd=1
[7,2,5,8]    → Sum=22 → 22%4=2 → odd=2
```

---

## Edge Case

### Input

```
n = 4
connections = [1,1,1,1]
k = 2
```

### Output

```
0
```

---

# Question 4: Maximum Number of Subsequences After One Inserting

You are given a string **`s`** consisting of uppercase English letters.

The task is to determine the **maximum number of `"LCT"` subsequences** after inserting **at most one uppercase letter** anywhere in the string.

---

## Definition

A **subsequence** is formed by deleting characters without changing order.

Example:

```
"LCT" is a subsequence of "ALCTB"
```

---

## Allowed Operations

You may:

1. **Insert nothing**
2. **Insert exactly one uppercase letter** anywhere (including start or end)

---

## Objective

Maximize the number of subsequences equal to:

```
"LCT"
```

---

## Example

Original string:

```
LLCTT
```

Existing subsequences:

```
2
```

If we insert `"C"`:

```
LLCCTT
```

Total `"LCT"` subsequences:

```
4
```

---

## Strategy

1. Count existing `"LCT"` subsequences.
2. Try inserting:

    * `"L"` → creates extra `"CT"` subsequences
    * `"T"` → creates extra `"LC"` subsequences
    * `"C"` → creates extra `"LT"` subsequences
3. Return:

```
existing + max(additional gain)
```

---

# Question 5: Google – Signal Stability Monitoring

Google SRE monitors a stream of signal values.

A **Stable Segment** is defined as a contiguous subarray where:

```
max(signals[i..j]) − min(signals[i..j]) ≤ k
```

---

## Function

```
findLongestStableSegment(signals, k)
```

### Parameters

* `int signals[n]` — signal values
* `int k` — instability threshold

### Returns

* `int` — length of the longest stable segment

---

## Constraints

```
1 ≤ n ≤ 10^6
0 ≤ signals[i] ≤ 10^9
0 ≤ k ≤ 10^9
```

Time complexity required:

```
O(n)
```

---

## Example

### Input

```
signals = [10, 2, 4, 8, 15, 3]
k = 6
```

### Analysis

```
[2,4,8] → max=8 min=2 → diff=6 → valid
```

Length:

```
3
```

### Output

```
3
```

---

# Question 6: Google – Optimized Compute Clusters

Google Cloud evaluates clusters of tasks to detect **stable and efficient compute segments**.

A **Stable Cluster** must satisfy:

### Stability

```
max(loads[i..j]) − min(loads[i..j]) ≤ K
```

### Efficiency

```
sum(loads[i..j]) ≥ S
```

---

## Function

```
findShortestStableCluster(loads, k, s)
```

### Parameters

* `int loads[n]`
* `int k`
* `long s`

### Returns

```
Length of the shortest valid segment
Return -1 if none exists
```

---

## Example

### Input

```
loads = [10, 12, 15, 7, 9, 8, 11]
k = 5
s = 25
```

### Analysis

```
[10,12,15]
Max-Min = 5
Sum = 37
Length = 3
```

### Output

```
3
```

---

# Question 7: Google – The Reversing Sequence Game

A card game is played with an array of integers.

Players:

```
P1 and P2
```

Both play **optimally**.

P1 moves first.

---

## Rules

1. On a turn, a player **must take the first element** of the array.
2. The card value is added to their score.
3. The card is removed.

### Twist

If the removed card is **even**:

```
The remaining array is reversed
```

---

## Objective

Return:

```
P1_score − P2_score
```

---

## Function

```
calculateScoreDifference(cards)
```

### Parameters

```
int cards[n]
```

### Returns

```
long
```

---

## Constraints

```
1 ≤ n ≤ 5000
1 ≤ cards[i] ≤ 10^9
Time Limit: 2s
```

---

## Example

### Input

```
cards = [2, 3, 4, 5]
```

### Game Simulation

```
P1 takes 2
Array becomes [3,4,5] → reversed → [5,4,3]
P1 score = 2
```

```
P2 takes 5
Array remains [4,3]
P2 score = 5
```

```
P1 takes 4
Array becomes [3] → reversed
P1 score = 6
```

```
P2 takes 3
P2 score = 8
```

### Output

```
6 − 8 = -2
```

---

If you want, I can also give you **optimized algorithms + C++ solutions for all 7 questions (Amazon + Google OA style)** which are **interview-ready O(n) / O(n log n)**.
