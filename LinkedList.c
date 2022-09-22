#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void insertAtEnd(struct Node *ptr, int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode->data = data;
    newNode->next = NULL;
    ptr->next = newNode;
}

void insertAtStart(struct Node *ptr, int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = ptr->data;
    newNode->next = ptr->next;

    ptr->data = data;
    ptr->next = newNode;
}

void insertAfterNode(struct Node *ptr, int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = ptr->next;

    ptr->next = newNode;
}

void insertAtIndex(struct Node *ptr, int data, int index)
{
    // At begining
    if (index == 0)
    {
        insertAtStart(ptr, data);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            // Linked list ends before reaching index then break out of loop
            if (ptr != NULL)
            {
                ptr = ptr->next;
            }
            else
            {
                break;
            }
        }
        // only add if index is in range of linked list size
        if (ptr != NULL)
        {
            insertAfterNode(ptr, data);
        }
    }
}

int main(int argc, char const *argv[])
{
    struct Node *linkedList, *second, *third, *fourth;
    linkedList = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    linkedList->data = 7;

    insertAtEnd(linkedList, 12);
    insertAtEnd(linkedList, 41);
    insertAtEnd(linkedList, 47);
    insertAtEnd(linkedList, 49);
    insertAtEnd(linkedList, 73);

    insertAtIndex(linkedList, 31, 3);

    traverse(linkedList);
    return 0;
}
