class Solution:
    def __init__(self):
        # All possible single-step moves on the lock pattern grid
        # Each tuple represents a move as (row change, column change)
        self.SINGLE_STEP_MOVES = [
            (0, 1),  (0, -1),
            (1, 0),  (-1, 0),  
            (1, 1),  (-1, 1),
            (1, -1), (-1, -1), 
            (-2, 1), (-2, -1),
            (2, 1),  (2, -1),  
            (1, -2), (-1, -2),
            (1, 2),  (-1, 2)
        ]

        # Moves that require a dot to be visited in between
        # These moves jump over a dot, which must have been previously visited
        self.SKIP_DOT_MOVES = [
            (0, 2),   (0, -2),
            (2, 0),   (-2, 0),  
            (-2, -2), (2, 2),
            (2, -2),  (-2, 2)  
        ]
    def numberOfPatterns(self, m: int, n: int) -> int:
        totalPatterns = 0
        # Start from each of the 9 dots on the grid
        for row in range(3):
            for col in range(3):
                visitedDots = [[False for _ in range(3)] for _ in range(3)]
                # Count patterns starting from this dot
                totalPatterns += self.countPatternsFromDot(m, n, 1, row, col, visitedDots)
        return totalPatterns

    def countPatternsFromDot(self, m: int, n: int, currentLength: int, currentRow: int,
                             currentCol: int, visitedDots: list[list[bool]]) -> int:
        # Base case: if current pattern length exceeds n, stop exploring
        if currentLength > n:
            return 0

        validPatterns = 0
        # If current pattern length is within the valid range, count it
        if currentLength >= m:
            validPatterns += 1

        # Mark current dot as visited
        visitedDots[currentRow][currentCol] = True

        # Explore all single-step moves
        for move in self.SINGLE_STEP_MOVES:
            newRow = currentRow + move[0]
            newCol = currentCol + move[1]
            if self.isValidMove(newRow, newCol, visitedDots):
                # Recursively count patterns from the new position
                validPatterns += self.countPatternsFromDot(
                    m, n, currentLength + 1, newRow, newCol, visitedDots)

        # Explore all skip-dot moves
        for move in self.SKIP_DOT_MOVES:
            newRow = currentRow + move[0]
            newCol = currentCol + move[1]
            if self.isValidMove(newRow, newCol, visitedDots):
                # Check if the middle dot has been visited
                middleRow = currentRow + move[0] // 2
                middleCol = currentCol + move[1] // 2
                if visitedDots[middleRow][middleCol]:
                    # If middle dot is visited, this move is valid
                    validPatterns += self.countPatternsFromDot(
                        m, n, currentLength + 1, newRow, newCol, visitedDots)

        # Backtrack: unmark the current dot before returning
        visitedDots[currentRow][currentCol] = False
        return validPatterns  
    def isValidMove(self, row: int, col: int, visitedDots: list[list[bool]]) -> bool:
        # A move is valid if it's within the grid and the dot hasn't been
        # visited
        return 0 <= row < 3 and 0 <= col < 3 and not visitedDots[row][col]

if __name__ == "__main__":
    solution = Solution()
    m, n = 1, 2
    print("Number of valid patterns:", solution.numberOfPatterns(m, n))
