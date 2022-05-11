#include<stdio.h>

int main()
{
    int arr [10];
    printf("Enter the elements of array: ");
    for(int i=0; i<10; ++i)
        scanf("%d", &arr[i]);
        
    printf("Elements of array are: ");
    for(int i=0; i<10; ++i)
        printf("%d ", arr[i]);
    
    return 0;
}

