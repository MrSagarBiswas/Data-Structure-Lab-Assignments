#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
struct Node * head = NULL;
struct Node * tail = NULL;

void create(int A[], int n)
{
    struct Node * temp, *last;
    head = (struct Node *) malloc (sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node * temp)
{
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node * search (struct Node * p, int key)
{
    if(p == NULL)
        return NULL;
    if(p -> data == key)
        return p;
    return search(p->next, key);
}

void insert(int data, int pos)
{
    struct Node * p, *temp;
    if(pos == 0)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    else if(pos > 0)
    {
        p = head;
        for(int i = 1; i <= pos-1 && p; i++)
        {
            p = p->next;
        }
        if(p)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
        }
        else
            printf("Index is not valid\n");
    }
}

void delete(int pos)
{
    struct Node * p = head;
    struct Node * q = NULL;
    if(pos == 1)
    {
        head = head->next;
        free(p);
    }
    else if(pos > 0)
    {
        for(int i = 0; i < pos-1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            free(p); 
        }
    }
}

void recursive_reverse(struct Node * p, struct Node * q)
{
    if(p == NULL)
    {
        head = q;
        return;
    }

    recursive_reverse(p->next, p);
    p->next = q;
}

int main()
{
    for (size_t i = 0; i < 5; i++)
    {
        insert(i+1,i);
    }
    
    display(head);
    recursive_reverse(head, NULL);
    display(head);
}