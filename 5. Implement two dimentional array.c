#include <stdio.h>

int main()
{
    int rows = 3, cols = 3;
    int arr[rows][cols];
    printf("Enter elements of 2D array: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\nElements of 2D array: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}