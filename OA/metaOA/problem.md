
---

# Meta OA – Cave Expedition

A group of explorers is heading for an expedition into a cave. The cave can be represented as a **rectangular map consisting of N rows and M columns**.

* **Rows** represent levels of the cave and are numbered from **0 to N−1** from top to bottom.
* **Columns** are numbered from **0 to M−1** from left to right and represent consecutive chambers on each level of the cave.

Some chambers are safe and some are unsafe:

* Chambers marked **'.'** are **safe** and can be entered.
* Chambers marked **'x'** are **unsafe** (contain too much debris) and **cannot be entered**.

The expedition:

* **Starts at the top-left corner** of the cave: **(0, 0)**.
* **Goal:** reach the **exit chamber** at **(N−1, M−1)**.

### Allowed Moves

From a chamber **(R, C)** the explorers can move to only one of the following chambers:

* **Left:** (R, C − 1)
* **Right:** (R, C + 1)
* **Down:** (R + 1, C)

Important constraints:

* Moving **upwards is not allowed** because climbing up is too dangerous.
* Once explorers move to a lower level, they **cannot return to upper levels**.

### Additional Rules

* Explorers want to **visit as many chambers as possible**.
* The cave passages may be very narrow, so explorers **cannot revisit a chamber** they have already entered.
* Chambers **outside the map** are considered unsafe.
* The expedition **cannot enter unsafe chambers ('x')**.

### Task

Find the **maximum number of chambers** the explorers can visit on a path from **(0,0)** to **(N−1,M−1)**.

If it is **impossible to reach the exit chamber**, the expedition must be **cancelled**, and the function should return **−1**.

---

# Function Specification

```
int solution(vector<string> &B);
```

### Input

* `B` — an array of **N strings**, each of length **M**.
* Each string represents one row of the cave map.
* Each character is either:

    * `'.'` → safe chamber
    * `'x'` → unsafe chamber

### Output

* Return the **maximum number of chambers** that can be visited while traveling from **(0,0)** to **(N−1,M−1)**.
* If reaching the exit is **not possible**, return **−1**.

---

# Example 1

```
B = [
"...",
".x.",
"..."
]
```

Output:

```
9
```

Explanation:

One of the **longest valid paths** allows the explorers to visit **9 chambers** while moving only **left, right, or down**.

---

# Example 2

```
B = [
".x...",
".x...",
"...x."
]
```

Output:

```
-1
```

Explanation:

Reaching the exit chamber would require **moving up**, which is not allowed.
Therefore, the explorers **cannot reach the exit**.

---

# Example 3

```
B = [
".....",
".xxxx",
"...x.",
"...x.",
"....."
]
```

Output:

```
14
```

Explanation:

The **longest valid path** from the entrance to the exit visits **14 chambers**, and the path is **unique**.

---
