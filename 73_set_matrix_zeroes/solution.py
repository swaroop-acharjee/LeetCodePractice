from typing import List


class Solution:
  def setZeroes(self, matrix: List[List[int]]) -> None:
    ROWS, COLS = len(matrix), len(matrix[0])
    unique_rows, unique_cols = set(), set()

    """
    Finding the unique set of rows and cols
    where 0 is present
    """
    for i in range(ROWS):
      for j in range(COLS):
        if matrix[i][j] == 0:
          unique_rows.add(i)
          unique_cols.add(j)
    
    """
    Making all the rows as 0
    """
    for row in unique_rows:
      for col in range(COLS):
        matrix[row][col] = 0

    """
    Making all the cols as 0
    """
    for col in unique_cols:
      for row in range(ROWS):
        matrix[row][col] = 0


matrix = [[2, 4, 3], [1, 0, 0]]
n, m = 2, 3
solution_obj = Solution()
solution_obj.setZeroes(matrix)
print(matrix)
