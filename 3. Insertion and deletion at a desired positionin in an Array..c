#include<stdio.h>


int arr[10];

int* insertion(int pos, int data)
{
    if(pos+1 < 10)
    {
        for(int i=10-1; i > pos; --i)
            arr[i] = arr[i-1];
        arr[pos] = data;
        
        return arr;
    }
    
    int arr1[pos+1];
    arr1[pos] = data;
    return arr1;
}

void print(int * arr, int size )
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    arr[0] = 10;
    int * arr = insertion(5, 20);
    print(arr, 10);
}