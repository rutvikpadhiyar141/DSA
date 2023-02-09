#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *Sptr)
{
    if (Sptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *Sptr)
{
    if (Sptr->top == Sptr->size - 1)
        return 1;
    return 0;
}

void push(struct Stack *Sptr, int element)
{
    if (isFull(Sptr))
        return;

    Sptr->arr[Sptr->top + 1] = element;
    Sptr->top++;
    return;
}

int pop(struct Stack *Sptr)
{
    if (isEmpty(Sptr))
        return;

    Sptr->top--;
    return Sptr->arr[Sptr->top + 1];
}

int main()
{
    // Method 1
    /*
        struct Stack S;
        S.size = 20;
        S.top = -1;
        S.arr = (int *)malloc(S.size * sizeof(int));
    */

    // Method 2
    struct Stack *S;
    S->size = 20;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));

    push(S, 23);
    push(S, 25);
    push(S, 27);

    pop(S);
    for (int i = 0; i < S->top + 1; i++)
        printf("%d\n", S->arr[i]);
    printf("%d\n", S->arr[S->top]);

    return 0;
}