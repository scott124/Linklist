#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

typedef struct node {
    int data;
    struct node *link;
}Node;

Node * insert(Node *first, int data)
{
    Node * new = malloc(sizeof(Node));
    new->data = data;
    new->link = NULL;

    if ( first ) {
        new->link = first->link;
        first->link = new;
    }
    else 
        first = new;
        
    return first;
}
void printList(Node *first)
{
    while (first != NULL)
    {
        printf("%d->",first->data);
        first=first->link;
    }
    printf("NULL\n");
}
Node * invert(Node *first)
{
    Node *p = NULL, *q = NULL, *r = NULL;
    p = first;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;
    return first;
}
int main(int argc, char ** argv)
{
    Node * first = NULL;

    first = insert(first, 1);
    first = insert(first, 2);
    first = insert(first, 3);
    first = insert(first, 4);
    first = insert(first, 5);
    first = insert(first, 6);

    printList(first);
    first = invert(first);
    printList(first);
    return 0;
}

