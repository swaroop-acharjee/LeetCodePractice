from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1, 1]]

        result_list: List = [[1], [1, 1]]
        for row in range(2, numRows):
            current_row: list = [1 for _ in range(row + 1)]
            for idx in range(len(result_list[row - 1]) - 1):
                current_row[idx + 1]: int = (
                    result_list[row - 1][idx] + result_list[row - 1][idx + 1]
                )
            result_list.append(current_row)
        return result_list


solution_obj = Solution()
print(solution_obj.generate(5))
