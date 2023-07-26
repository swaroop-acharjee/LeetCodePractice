from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n, m = len(matrix), len(matrix[0])
        u_row, u_col = set(), set()
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    u_row.add(i)
                    u_col.add(j)

        for row in u_row:
            for i in range(m):
                matrix[row][i] = 0

        for col in u_col:
            for i in range(n):
                matrix[i][col] = 0


matrix = [[2, 4, 3], [1, 0, 0]]
n, m = 2, 3
solution_obj = Solution()
solution_obj.setZeroes(matrix)
print(matrix)
