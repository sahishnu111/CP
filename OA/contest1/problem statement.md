#question 1
You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the sum of every number between the range [i, j] (inclusive).




#question 2
Amazon Code Question: Security Risk Level

Amazon is launching a revolutionary security feature that incorporates an advanced antivirus program, adept at identifying and halting potential threats. This framework manages n active programs, each with a unique Program Identifier (PID).

The antivirus program evaluates the overall security risk of the system using a specialized algorithm.
The Algorithm

    The algorithm analyzes contiguous subarrays of Program Identifiers (PIDs) represented by the array pid.
    For each subarray, it calculates the sum of the PIDs and divides this sum by a constant k.
    The remainder obtained from this division is compared to the number of programs (length) in the subarray.
    A subarray is flagged as malicious if:

Sum of Subarray(modk)=Length of Subarray

    The overall security risk is determined by the total count of such flagged (malicious) subarrays.

Function Description

Complete the function findSecurityLevel in the editor.

Parameters:

    int pid[n]: An array of integers denoting the PIDs of the programs.
    int k: An integer with which the remainder is checked.

Returns:

    long: A long integer denoting the overall security risk (total count of malicious subarrays).

Constraints

    1≤n≤2×10^5
    1≤pid[i]≤10^9
    1≤k≤10^9

Example

Input:

    n = 4
    pid = [1, 3, 2, 4]
    k = 4

Analysis: There are 2 different malicious contiguous subarrays:

    **Subarray [1]** (index 0 to 0):

    Sum = 1, Length = 1.
    1(mod4)=1. Remainder (1) equals Length (1). Flagged.

    **Subarray [2, 4]** (index 2 to 3):

    Sum = 2+4=6, Length = 2.
    6(mod4)=2. Remainder (2) equals Length (2). Flagged.

Non-malicious example:

    **Subarray [3, 2]** (index 1 to 2):
    Sum = 3+2=5, Length = 2.
    5(mod4)=1. Remainder (1) does not equal Length (2). Not flagged.

Output:

    2

Sample Case 0

Input:

    n = 5
    pid = [1, 4, 2, 3, 5]
    k = 100

Output:

    1

Explanation: The only malicious subarray is [1] because 1(mod100)=1, which equals the length








#question 3
Amazon Code Question 2: AWS Load Balancing

AWS dynamically routes incoming traffic to a distributed cluster of n servers. Each server currently maintains an active connection count. The load balancer analyzes segments of servers to find optimally balanced routing paths.

The system evaluates the balance of contiguous subarrays of servers using the following logic:

    The algorithm analyzes contiguous subarrays of server connection counts represented by the array connections.
    For each subarray, it calculates the sum of the connections and divides this sum by a constant calibration factor k.
    The algorithm also counts the number of servers in the subarray that have an odd number of connections (representing irregular load spikes).
    A subarray is flagged as optimally balanced if the remainder obtained from the division equals the total count of odd-connection servers within that same subarray.
    The overall system stability score is determined by the total count of such optimally balanced subarrays.

Function Description

Complete the function findBalancedRouting in the editor below.

Parameters:

    int connections[n]: an array of integers denoting the active connections of the servers.
    int k: an integer representing the calibration factor.

Returns:

    long: an integer denoting the overall system stability score (total count of optimally balanced subarrays).

Constraints

    1≤n≤2×10^5
    1≤connections[i]≤10^9
    1≤k≤10^9

Sample Case 0

Input:

    n = 5
    connections = [2, 3, 1, 4, 5]
    k = 3

Output:

    2

Explanation: There are 2 optimally balanced contiguous subarrays:

    **Subarray [1]** (index 2 to 2):

    Sum = 1.
    Remainder: 1(mod3)=1.
    Odd-connection servers: 1 (the server with 1 connection).
    Remainder (1) equals Odd count (1). Flagged.

    **Subarray [3, 1, 4]** (index 1 to 3):

    Sum = 3+1+4=8.
    Remainder: 8(mod3)=2.
    Odd-connection servers: 2 (the servers with 3 and 1 connections).
    Remainder (2) equals Odd count (2). Flagged.

Complex Test Case

Input:

    n = 6
    connections = [4, 7, 2, 5, 8, 3]
    k = 4

Output:

    3

Explanation:

    [7, 2] -> Sum = 9. 9(mod4)=1. Odd count = 1. (Match)
    [5] -> Sum = 5. 5(mod4)=1. Odd count = 1. (Match)
    [3] -> Sum = 3. 3(mod4)=3. Odd count = 1. (No Match)
    [7, 2, 5, 8] -> Sum = 22. 22(mod4)=2. Odd count = 2. (Match)

Edge Case to Watch Out For

Input:

    n = 4
    connections = [1, 1, 1, 1]
    k = 2

Output:

    0



#question4
3628. Maximum Number of Subsequences After One Inserting

Problem Description

You are given a string s consisting of uppercase English letters.

The task is to find the maximum number of "LCT" subsequences that can be formed after inserting at most one uppercase English letter into the string.

A subsequence is a sequence that can be derived from the original string by deleting some or no elements without changing the order of the remaining elements. For example, "LCT" is a subsequence of "ALCTB" (formed by taking the 2nd, 3rd, and 5th characters).

You can:

Keep the string as is (insert nothing) Insert exactly one uppercase English letter at any position in the string (including at the beginning or end) The goal is to maximize the number of "LCT" subsequences in the resulting string.

For example, if the original string is "LLCTT", it contains 2 "LCT" subsequences (using the first L with C and first T, and first L with C and second T). If we insert another "C" at position 3 to get "LLCCTT", we would have 4 "LCT" subsequences total.

The solution works by:

First counting the existing "LCT" subsequences in the original string by enumerating each "C" as the middle character and counting valid "L"s before it and "T"s after it Then considering what happens when we insert one additional letter: Inserting "L": counts additional "CT" subsequences that would form with the new "L" Inserting "T": counts additional "LC" subsequences that would form with the new "T" Inserting "C": counts additional "LT" subsequences that would form with the new "C" in the middle The final answer is the sum of the original count plus the maximum gain from inserting one letter.



#question5
Google Interview Question: Signal Stability Monitoring

Google’s Site Reliability Engineering (SRE) team is monitoring a stream of data signals from a global network. Each signal is represented by an integer value in an array signals.

To ensure network stability, a "Stable Segment" is defined as a contiguous substring (subarray) of signals where the difference between the maximum signal value and the minimum signal value within that segment does not exceed a threshold k.

Your task is to find the length of the longest stable segment in the given signal stream.
The Criteria

A substring from index i to j is considered stable if:

max(signals[i…j])−min(signals[i…j])≤k
Function Description

Complete the function findLongestStableSegment in the editor.

Parameters:

    int signals[n]: An array of integers representing the signal values.
    int k: An integer representing the maximum allowed difference (instability threshold).

Returns:

    int: The length of the longest contiguous stable subarray.

Constraints

    1≤n≤106
    0≤signals[i]≤109
    0≤k≤109
    Time Limit: 1.0s (Requires an O(n) solution).

Example

Input:

    signals = [10, 2, 4, 8, 15, 3]
    k = 6

Analysis:

    Subarray [2, 4, 8]: Max=8, Min=2. 8−2=6≤6. (Valid, Length = 3)
    Subarray [4, 8]: Max=8, Min=4. 8−4=4≤6. (Valid, Length = 2)
    Subarray [10, 2]: Max=10, Min=2. 10−2=8>6. (Invalid)
    Subarray [8, 15]: Max=15, Min=8. 15−8=7>6. (Invalid)

Output:

    3

Complex Test Case (Stress Test)

Input:

    signals = [1, 5, 8, 10, 12, 14, 19]
    k = 5

Output:

    4 (Explanation: The subarray [8, 10, 12, 14] has Max=14, Min=8, Diff=6 (Invalid). But [10, 12, 14] is valid. The longest is actually [8, 10, 12] or [10, 12, 14], both length 3. Wait—let's look at [1, 5], [5, 8, 10]. The longest segment is [8, 10, 12] or similar.)




#question6
Google OA Question: Optimized Compute Clusters

Google Cloud is designing a new load-balancer for its "Elastic Compute" clusters. You are given an array loads representing the CPU demand of n consecutive tasks.

A "Stable Cluster" is defined as a contiguous segment of tasks that meets two requirements:

    Stability: The difference between the highest demand task and the lowest demand task in the segment must not exceed K.
    Efficiency: The total sum of demands in the segment must be at least S.

Find the length of the shortest Stable Cluster. If no such cluster exists, return -1.
The Algorithm

A subarray from index i to j is a "Stable Cluster" if:

    max(loads[i…j])−min(loads[i…j])≤K
    ∑jx=iloads[x]≥S

Function Description

Complete the function findShortestStableCluster in the editor.

Parameters:

    int loads[n]: An array of integers representing task CPU demands.
    int k: The maximum allowed demand variance.
    long s: The minimum required total cluster demand.

Returns:

    int: The length of the shortest valid segment, or -1.

Example

Input:

    loads = [10, 12, 15, 7, 9, 8, 11]
    k = 5
    s = 25

Analysis:

    Subarray [10, 12, 15]: Max-Min = 5 (≤5), Sum = 37 (≥25). Length = 3.
    Subarray [7, 9, 8, 11]: Max-Min = 4 (≤5), Sum = 35 (≥25). Length = 4.
    Subarray [15, 7]: Max-Min = 8 (>5). (Invalid)

Output: 3 (Shortest valid segment is [10, 12, 15]).



#question7
Google OA Question: The Reversing Sequence Game

Google is developing a new strategy-based card game for its internal gaming platform. The game is played with a sequence of n integer cards represented by the array cards. Two players, P1 and P2, play optimally to maximize their own total score. P1 always goes first.
The Rules

    On a player's turn, they must take the first element (the head) of the current array.
    The value of that card is added to the player's total score, and the card is removed from the array.
    The Twist: If the card just removed is even, the remaining array is immediately reversed before the next player's turn begins.
    The game ends when the array is empty.

Your task is to calculate the final value of (Score of P1)−(Score of P2) assuming both players play optimally.
Function Description

Complete the function calculateScoreDifference in the editor.

Parameters:

    int cards[n]: An array of integers representing the sequence of cards.

Returns:

    long: The value of P1_score−P2_score.

Constraints

    1≤n≤5000
    1≤cards[i]≤109
    Time Limit: 2.0s
    Memory Limit: 512MB

Example

Input: cards = [2, 3, 4, 5]

Analysis:

    P1's turn: Takes 2.

    2 is even, so the remaining array [3, 4, 5] is reversed to [5, 4, 3].
    P1 Score = 2.

    P2's turn: Takes 5 (the first element of the reversed array).

    5 is odd, so the remaining array [4, 3] stays as is.
    P2 Score = 5.

    P1's turn: Takes 4.

    4 is even, so the remaining array [3] is reversed (still [3]).
    P1 Score = 2+4=6.

    P2's turn: Takes 3.

    P2 Score = 5+3=8.

Output: 6−8=−2



