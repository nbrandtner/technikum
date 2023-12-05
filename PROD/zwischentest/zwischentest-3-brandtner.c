#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum genre {
    HORROR,
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

void notValid();
void freeLists(struct bookNode *head,struct borrowNode *headBorrow);
int countBookList(struct bookNode *head);
int countBorrowList(struct borrowNode *head);
struct bookNode *createBookNode(char *tempTitle, enum genre tempGenre, int tempYear, int tempAmount);
void insertBook(struct bookNode **head);
struct borrowNode *createBorrowNode(char *title, char *name);
void borrowBook(struct bookNode **head, struct borrowNode **headBorrow);
void returnbook();
void printList(struct bookNode **head);
void printListInOrder(struct bookNode **head);

// Funktion, die eine Fehlermeldung ausgibt
void notValid(){
    printf("\nUngueltige Eingabe!");
}
// Funktion, die Speicher der Bücher freigibt
void freeLists(struct bookNode *head, struct borrowNode *headBorrow) {
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
    scanf("%31s", tempTitle);

    while(1){
    printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf("%d",&tempGenre);
        if(tempGenre>=0&&tempGenre<=3){
            break;
        }else{
            notValid();
        }
    }
    while(1){
    printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf("%d",&tempYear);
        if(tempYear>0){
            break;
        }else{
            notValid();
        }
    }
    while(1){
    printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d",&tempAmount);
        if(tempAmount>0){
            break;
        }else{
            notValid();
        }
    }
    
    struct bookNode *newNode = createBookNode(tempTitle, tempGenre-1, tempYear, tempAmount);

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

void borrowBook(struct bookNode **head, struct borrowNode **headBorrow){
    struct borrowNode *current=*headBorrow;
    int borrowBook;
    int countBook=countBookList(*head);
    int countBorrow=countBorrowList(*headBorrow);
    char tempTitle[32]="";
    char tempName[32]="";
    if(countBook==0){
        printf("\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }
    printList(head);
    while(1){
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ",countBook);
        scanf("%d",&borrowBook);
        if(borrowBook<1||borrowBook>countBook){
            notValid();
            continue;
        }else{
            struct bookNode *bookToBorrow = *head; // Initialize a pointer to the head of the book list
            for (int i = 1; i < borrowBook; i++) { // Move the pointer to the selected book
                bookToBorrow = bookToBorrow->next;
            }
            strcpy(tempTitle, bookToBorrow->content.title); // Copy the title of the selected book
        }
        printf("\nGeben Sie Ihren Namen ein: ");
        scanf("%31s",tempName);
        for(int i=0;i<countBorrow;i++){
            if(strcmp(current->title,tempTitle)==0&&strcmp(current->name,tempName)==0){
                printf("\nSie haben diesen Titel bereits ausgeliehen!");
                return;
            }
            current = current->next;
        }
        break;
    }
    struct borrowNode *newNode = createBorrowNode(tempTitle, tempName);

    newNode->next = *headBorrow;
    *headBorrow = newNode;
}

void returnbook(){
    
}

void printList(struct bookNode **head){
    struct bookNode *current=*head;
    for(int i=0;i<countBookList(*head);i++){
        printf("\n%d: %s, %s (%d)", i+1,current->content.title,genreNames[current->content.bookGenre],current->content.year);
        current = current->next; 
    }
    printf("\n");
}

void printListInOrder(struct bookNode **head) {
    int count = countBookList(*head); // Zähle die Anzahl der Elemente in der Liste

    struct bookNode **tempArray = (struct bookNode **)malloc(count * sizeof(struct bookNode *));
    if (tempArray == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Fülle das temporäre Array mit den Knoten der Liste
    struct bookNode *current = *head;
    for (int i = 0; i < count; i++) {
        tempArray[i] = current;
        current = current->next;
    }

    // Sortiere das temporäre Array nach dem Jahr
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tempArray[j]->content.year > tempArray[j + 1]->content.year) {
                struct bookNode *temp = tempArray[j];
                tempArray[j] = tempArray[j + 1];
                tempArray[j + 1] = temp;
            }
        }
    }

    // Gib die sortierte Liste aus
    for (int i = 0; i < count; i++) {
        printf("\n%d: %s, %s (%d)", i + 1, tempArray[i]->content.title, genreNames[tempArray[i]->content.bookGenre], tempArray[i]->content.year);
    }
    printf("\n");

    free(tempArray); // Freigabe des allokierten temporären Arrays
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
                returnbook();
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
                notValid();
                continue; // Skip the rest of the code and start the next iteration
        }
    }
}
