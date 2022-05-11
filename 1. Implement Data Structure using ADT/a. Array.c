#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
    int size;
};

struct Array arr = {NULL, 10}; // default size and length
void initialize(int size)
{
    arr.size = size;
    arr.A = (int *) malloc (arr.size*sizeof(int));
}
void insert(int index, int data)
{
    if(index < 0 || index > arr.size)
        return;
    arr.A[index] = data;
}

void display()
{
    for(int i = 0; i<arr.size; i++)
        printf("%d ", arr.A[i]);
    printf ("\n");
}

int get(int index)
{
    if(index < 0 || index > arr.size)
        return -1;
    return arr.A[index];
}
void set(int index, int value)
{
    if(index < 0 || index > arr.size)
        return -1;
    arr.A[index] = value;
}

int main()
{
    initialize(10);
    for (int i = 0; i < 5; ++i)
    {
        insert (i, i+1);
    }
    display();
    printf("%d", get (4));
}