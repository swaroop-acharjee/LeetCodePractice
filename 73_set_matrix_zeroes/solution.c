#include <stdio.h>

int isPresent(int arr[], int x, int size)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return 1;
    return 0;
}

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int ROWS = matrixSize;
    int COLS = *matrixColSize;
    int unique_rows[200], row_idx = 0;
    int unique_cols[200], col_idx = 0;
    int i, j;

    for (i = 0; i < 200; i++)
    {
        unique_rows[i] = -1;
        unique_cols[i] = -1;
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (isPresent(unique_rows, i, 200) == 0)
                    unique_rows[row_idx++] = i;
                if (isPresent(unique_cols, j, 200) == 0)
                    unique_cols[col_idx++] = j;
            }
        }
    }

    for (i = 0; i < row_idx; i++)
    {
        for (j = 0; j < COLS; j++)
            matrix[unique_rows[i]][j] = 0;
    }

    for (j = 0; j < col_idx; j++)
    {
        for (i = 0; i < ROWS; i++)
            matrix[i][unique_cols[j]] = 0;
    }
}

int main()
{
    int matrix[][4] = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    displayMatrix(matrix, 3, 4);

    return 0;
}