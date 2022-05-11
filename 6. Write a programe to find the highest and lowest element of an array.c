#include<stdio.h>

int return_optimal(int arr[], int max)
{
    int opt = arr[0];
    if(max)
    {
        for(int i = 0; i < 10; i++)
        {
            if(arr[i] >  opt)
                opt = arr[i];
        }
        
        return opt;
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(arr[i] <  opt)
            opt = arr[i];
    }
        
    return opt;
    
}

int main()
{
    int arr[10];
    printf("Enter the elements: ");
    for(int i=0; i < 10; ++i)
        scanf("%d", &arr[i]);
        
    int max = return_optimal(arr, 1);
    int min = return_optimal(arr, 0);
    
    printf("MAX: %d\nMIN: %d", max, min);
}