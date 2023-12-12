#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

enum genre {
    HORROR=1,
    ABENTEUER,
    ROMANTIK,
    SACHBUCH
};
const char *genreNames[] = {
    "Horror",
    "Abenteuer",
    "Romantik",
    "Sachbuch"
};

struct book {
    char title[32];
    enum genre bookGenre;
    int year;
    int amount;
};
struct bookNode{
    struct book content;
    struct bookNode *next;
};
struct borrowNode{
    char title[32];
    char name[32];
    struct borrowNode *next;
};
void printList(struct bookNode **head);

void freeLists(struct bookNode *head, struct borrowNode *headBorrow) {// Funktion, die Speicher der Bücher freigibt
    struct bookNode *tempbook;
    struct borrowNode *tempborrow;
    while (head != NULL) {
        tempbook = head;
        head = head->next;
        free(tempbook);
    }
    while (headBorrow != NULL) {
        tempborrow = headBorrow;
        headBorrow = headBorrow->next;
        free(tempborrow);
    }
}
int countBookList(struct bookNode *head) {
    int count = 0;
    struct bookNode *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int countBorrowList(struct borrowNode *head) {
    int count = 0;
    struct borrowNode *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int getValidInput(char* prompt, int min, int max) {
    int input;
    while(1){
        printf("%s", prompt);
        scanf(" %d", &input);
        if(input >= min && input <= max){
            break;
        }else{
            printf("\nUngueltige Eingabe!");;
        }
    }
    return input;
}
struct bookNode *createBookNode(char* tempTitle, enum genre tempGenre, int tempYear, int tempAmount) {
    struct bookNode *newNode = (struct bookNode *)malloc(sizeof(struct bookNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newNode->content.title, tempTitle); // Copy the title string to the book structure
    newNode->content.bookGenre = tempGenre;
    newNode->content.year = tempYear;
    newNode->content.amount = tempAmount;
    newNode->next = NULL;
    return newNode;
}
void insertBook(struct bookNode **head) {
    char tempTitle[32]="";
    int tempGenre=0;
    int tempYear=0;
    int tempAmount=0;
    printf("\nGeben Sie den Titel ein: ");
    scanf(" %31s",tempTitle);
    tempGenre = getValidInput("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ", 1, 4);
    tempYear = getValidInput("\nGeben Sie das Erscheinungsjahr ein: ", 1, INT_MAX);
    tempAmount = getValidInput("\nGeben Sie ein wieviele Exemplare vorhanden sind: ", 1, INT_MAX);
    struct bookNode *newNode = createBookNode(tempTitle, tempGenre, tempYear, tempAmount);
    newNode->next = *head;
    *head = newNode;
}
struct borrowNode *createBorrowNode(char* tempTitle, char* tempName) {
    struct borrowNode *newNode = (struct borrowNode *)malloc(sizeof(struct borrowNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    strcpy(newNode->title, tempTitle);
    strcpy(newNode->name, tempName);
    newNode->next = NULL;
    return newNode;
}
void borrowBook(struct bookNode **head, struct borrowNode **headBorrow) {
    struct borrowNode *current = *headBorrow;
    struct bookNode *bookToBorrow = *head;
    int borrowBook;
    int countBook = countBookList(*head);
    int countBorrow = countBorrowList(*headBorrow);
    char tempTitle[32] = "";
    char tempName[32] = "";
    if (countBook == 0) {
        printf("\n\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }

    printList(head);
    while (1) {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", countBook);
        scanf("%d", &borrowBook);
        if (borrowBook < 1 || borrowBook > countBook) {
            printf("\nUngueltige Eingabe!");;
            continue;
        } else {
            for (int i = 1; i < borrowBook; i++) {
                bookToBorrow = bookToBorrow->next;
            }
            strcpy(tempTitle, bookToBorrow->content.title);
        }

        printf("\nGeben Sie Ihren Namen ein: ");
        scanf("%31s", tempName);
        int found = 0; // Flag to indicate if the user has already borrowed the book
        current = *headBorrow; // Reset current pointer to the beginning
        for (int i = 0; i < countBorrow; i++) {
            if (strcmp(current->title, tempTitle) == 0 && strcmp(current->name, tempName) == 0) {
                printf("\nSie haben diesen Titel bereits ausgeliehen!");
                found = 1; // Set the flag to indicate the book is already borrowed
                break; // Exit the loop since the book is found
            }
            current = current->next;
        }
        if (found) {
            break; // If the book is already borrowed, exit the borrowing process
        }
        if (bookToBorrow->content.amount == 0) {
            printf("\nBereits alle Exemplare ausgeliehen!");
            return;
        } else {
            bookToBorrow->content.amount--;
        }
        struct borrowNode *newNode = createBorrowNode(tempTitle, tempName); // Borrow the book if it's available
        newNode->next = *headBorrow;
        *headBorrow = newNode;
        break;
    }
}
void returnBook(struct bookNode **head,struct borrowNode **headBorrow) {
    struct borrowNode *current = *headBorrow;
    int countBorrow = countBorrowList(*headBorrow);
    int userBorrow = 0;
    if (countBorrow == 0) {
        printf("\n\nEs sind keine Titel ausgeliehen!");
        return;
    }
    for (int i = 0; i < countBorrow; i++) {
        printf("\n%d: %s geliehen von %s", i + 1, current->title, current->name);
        current = current->next;
    }
    while (1) {
        printf("\n\nWelchen Titel moechten Sie retournieren? (1-%d): ", countBorrow);
        scanf("%d", &userBorrow);
        if (userBorrow < 1 || userBorrow > countBorrow) {
            printf("\nUngueltige Eingabe!");;
            continue;
        }
        break;
    }
    current = *headBorrow;
    struct borrowNode *prev = NULL;
    for (int i = 1; i < userBorrow; i++) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL) {
        *headBorrow = current->next;
    } else {
        prev->next = current->next;
    }
    struct bookNode *bookToReturn = *head;
    while (strcmp(bookToReturn->content.title, current->title) != 0) {
        bookToReturn = bookToReturn->next;
    }
    bookToReturn->content.amount++; // Increment the available quantity
    free(current);
}
void printList(struct bookNode **head){
    struct bookNode *current=*head;
    for(int i=0;i<countBookList(*head);i++){
        printf("\n%d: %s, %s (%d)", i+1,current->content.title,genreNames[current->content.bookGenre-1],current->content.year);
        current = current->next; 
    }
    printf("\n");
}
void printListInOrder(struct bookNode **head) {
    int count = countBookList(*head); // Count the number of elements in the list
    struct bookNode **tempArray = (struct bookNode **)malloc(count * sizeof(struct bookNode *));
    if (tempArray == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    struct bookNode *current = *head;    // Fill the temporary array with the nodes from the list
    for (int i = 0; i < count; i++) {
        tempArray[i] = current;
        current = current->next;
    }
    for (int i = 0; i < count - 1; i++) {     // Sort the temporary array based on the year
        for (int j = 0; j < count - i - 1; j++) {
            if (tempArray[j]->content.year > tempArray[j + 1]->content.year) {
                struct bookNode *temp = tempArray[j];
                tempArray[j] = tempArray[j + 1];
                tempArray[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < count; i++) {     // Print the sorted list
        printf("\n%d: %s, %s (%d)", i+1, tempArray[i]->content.title, genreNames[tempArray[i]->content.bookGenre-1], tempArray[i]->content.year);
    }
    printf("\n");
    free(tempArray); // Free the allocated temporary array
}
int main(){
    char input;
    struct bookNode *head=NULL;
    struct borrowNode *headBorrow=NULL;
    while (1) {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");
        scanf(" %c", &input); // Note the space before %c to handle whitespace characters
        switch (input) {
            case 'n':
                insertBook(&head);
                break;
            case 'b':
                borrowBook(&head, &headBorrow);
                break;
            case 'r':
                returnBook(&head, &headBorrow);
                break;
            case 'l':
                printList(&head);
                break;
            case 's':
                printListInOrder(&head);
            break;
            case 'x':
                freeLists(head,headBorrow);
                return 0;
            default:
                printf("\nUngueltige Eingabe!");;
                continue; // Skip the rest of the code and start the next iteration
        }
    }
}
