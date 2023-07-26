#include <stdio.h>

#define INF 101

void swap(int *xp, int *yp)
{
    /*
    Function to swap two values
    */
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSortInRange(int *nums, int start_index, int end_index)
{
    /*
    Function to sort the value in the required range only
    */
    int i, j, min_idx;
    for (int i = start_index; i < end_index; i++)
    {
        min_idx = i;
        for (j = i + 1; j <= end_index; j++)
            if (nums[j] < nums[min_idx])
                min_idx = j;
        if (min_idx != i)
            swap(&nums[min_idx], &nums[i]);
    }
}

void nextPermutation(int *nums, int numsSize)
{
    int req_idx = -1;
    int next_max;
    int smallest_diff = INF;
    int i;
    int next_max_idx;

    /*
    Finding the breakpoint
    */
    for (i = 0; i < (numsSize - 1); i++)
        if (nums[i] < nums[i + 1])
            req_idx = i;

    /*
    If the break-point is not found,
    then the array is in descending order
    and it is the last permutation.
    The array is sorted order is returned.
    */
    if (req_idx == -1)
    {
        selectionSortInRange(nums, 0, (numsSize - 1));
        return;
    }

    /*
    Finding the smallest largest number
    of the value that is present in the breakpoint
    */
    for (i = req_idx + 1; i < numsSize; i++)
    {
        if ((nums[req_idx] < nums[i]) &&
            ((nums[i] - nums[req_idx]) < smallest_diff))
        {
            smallest_diff = nums[i] - nums[req_idx];
            next_max_idx = i;
        }
    }

    swap(&nums[req_idx], &nums[next_max_idx]);
    selectionSortInRange(nums, req_idx + 1, numsSize - 1);
}

void displayArray(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
        printf(" %d ", nums[i]);
    printf("\n");
}

int main()
{
    int nums[] = {2, 1, 5, 4, 3, 0, 0};
    int numsSize = 7;
    displayArray(nums, numsSize);
    nextPermutation(nums, numsSize);
    displayArray(nums, numsSize);
}