#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

struct node {
    int value;
    struct node* next;
};

int main(){
    struct node *head=NULL;
    int input;
    while (1) {
        printf("\nEnter number: ");
        scanf("%d", &input);
        if (input < 1) {
            break;
        }
        // add node to list
        struct node *newHead = (struct node *)malloc(sizeof(struct node));
        newHead->value = input;
        newHead->next = head;
        head=newHead;
        // print list
        }
    return 0;
}
