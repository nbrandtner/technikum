#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node;

void insertFront(node **head, int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Speicher konnte nicht zugewiesen werden.\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

void removeDuplicates(node *head)
{
    if (head == NULL)
        return;

    node *current = head;
    while (current->next != NULL)
    {
        if (current->value == current->next->value)
        {
            node *duplicate = current->next;
            current->next = duplicate->next;
            free(duplicate);
        }
        else
        {
            current = current->next;
        }
    }
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("%d", head->value);
        if (head->next != NULL)
            printf("-");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    int n;

    do
    {
        printf("\nInput: ");
        scanf("%d", &n);
        if (n > 0)
        {
            insertFront(&head, n);
            printList(head);
        }
    } while (n > 0);

    removeDuplicates(head);
    printf("\nFinal List: ");
    printList(head);

    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}