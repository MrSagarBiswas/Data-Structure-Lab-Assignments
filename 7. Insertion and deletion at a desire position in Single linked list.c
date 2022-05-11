#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * head = NULL;

void insert(int pos, int data)
{
    if(pos == 0)
    {
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        if(head != NULL)
        {
            temp->data = data;
            temp->next = head;
            head = temp;
        }
        else
        {
            temp->data = data;
            temp->next = NULL;
            head = temp;
        }
        
    }
    
    else
    {
        int c = 0;
        struct Node * curr = head;
        struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = data;
        while(c <= pos-2)
        {
            curr = curr->next;
            c++;
        }
        
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deletion(int pos)
{
    struct Node * temp;
    if(pos == 0)
    {
        temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        struct Node * curr;
        int c = 0;
        curr = head;
        while(c <= pos-2)
        {
            curr = curr->next;
            c++;
        }
        
        temp = curr->next;
        curr->next = temp->next;
        temp->next = NULL;
        free(temp);
        
    }
}

void print()
{
    struct Node * temp = head; 
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    for(int i=1; i<=5; ++i)
        insert(0, i);
        
    insert(2, 12);
    // deletion(0);
    deletion(2);
    print();
}