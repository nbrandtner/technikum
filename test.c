#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertFront(Node *head, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Speicher konnte nicht zugewiesen werden.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Funktion zum Entfernen direkt aufeinanderfolgender Duplikate
Node *removeConsecutiveDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *current = head;
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

// Funktion zum Ausgeben der Liste
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("-");
        head = head->next;
    }
    printf("\n");
}

// Funktion zum Freigeben des Speichers der Liste
void freeList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;
    int value;

    printf("Input: ");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        head = insertFront(head, value);
        printList(head);
        printf("Input: ");
    }

    // Entferne direkt aufeinanderfolgende Duplikate
    head = removeConsecutiveDuplicates(head);

    // Ausgabe der endgültigen Liste
    printf("Final List: ");
    printList(head);

    // Freigabe des Speichers
    freeList(head);

    return 0;
}
