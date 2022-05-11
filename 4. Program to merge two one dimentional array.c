#include <stdio.h>

int main()
{
    int a = 3;
    int b = 2;

    int arr1[a];
    int arr2[b];

    printf("Enter elements for arr1: ");
    for (int i = 0; i < a; i++)
        scanf("%d", &arr1[i]);

    printf("\nEnter elements for arr2: ");
    for (int i = 0; i < b; i++)
        scanf("%d", &arr2[i]);

    printf("\narr1: ");
    for (int i = 0; i < a; i++)
        printf("%d ", arr1[i]);

    printf("\narr2: ");
    for (int i = 0; i < b; i++)
        printf("%d ", arr2[i]);

    int arr[a + b];
    for (int i = 0; i < a + b; i++)
    {
        if (i < a)
        {
            arr[i] = arr1[i];
        }
        else
        {
            arr[i] = arr2[i - b - 1];
        }
    }

    printf("\nmerged array is: ");
    for (int i = 0; i < a + b; i++)
        printf("%d ", arr[i]);
}