#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Horror = 1,
    Abenteuer = 2,
    Romantik = 3,
    Sachbuch = 4
} genre_type;

const char *genreNames[] = {
        "Horror",
        "Abenteuer",
        "Romantik",
        "Sachbuch"
};

struct book {
    char title[32];
    genre_type genre;
    int year;
    int amount;
};

struct bookNode {
    struct book content;
    struct bookNode* next;
};

struct borrowNode {
    char title[32];
    char name[32];
    struct borrowNode* next;
};

struct bookNode* createBookNode(struct book book) {
    struct bookNode* node = (struct bookNode*)malloc(sizeof(struct bookNode));
    if (node != NULL) {
        node->content = book;
        node->next = NULL;
    }
    return node;
}


struct bookNode* insertBook(struct bookNode* head) {
    struct book book;
    int genreNumber;
    int year;
    int amount;
    printf("\nGeben Sie den Titel ein: ");
    scanf(" %s", book.title);

    // Clear input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    do {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf(" %d", &genreNumber);
        if (genreNumber < 1 || genreNumber > 4) {
            printf("\nUngueltige Eingabe!");
        }

    } while (genreNumber < 1 || genreNumber > 4);

    book.genre = (genre_type)genreNumber;
    
    do {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf(" %d", &year);
        if (year < 1) {
            printf("\nUngueltige Eingabe!");
        }

    } while (year < 1);
    book.year = year;
    
    do {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");        
        scanf(" %d", &amount);
        if (amount < 1) {
            printf("\nUngueltige Eingabe!");
        }

    } while (amount < 1);
    book.amount = amount;


    struct bookNode* newNode = createBookNode(book);
    newNode->next = head;
    return newNode;
}


struct borrowNode* createBorrowNode(char title[], char name[]) {
    struct borrowNode* node = (struct borrowNode*)malloc(sizeof(struct borrowNode));
    if (node != NULL) {
        strcpy(node->title, title);
        strcpy(node->name, name);
        node->next = NULL;
    }
    return node;
}

void printBookList(struct bookNode* head) {
    struct bookNode* current = head;
    int number = 1;
    while (current != NULL) {

        printf("\n%d: %s, %s (%d)", number, current->content.title, genreNames[current->content.genre - 1], current->content.year);

        number++;
        current = current->next;
    }
        printf("\n");
}

void printBorrowList(struct borrowNode* head) {
    struct borrowNode* current = head;
    int count = 1;
    while (current != NULL) {
        printf("\n%d: %s geliehen von %s", count, current->title, current->name);
        current = current->next;
        count++;
    }
    printf("\n");
}

struct bookNode* findBookByIndex(struct bookNode* head, int index) {
    struct bookNode* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

struct borrowNode* borrowBook(struct borrowNode* head, struct bookNode** bookHeadPtr) {
    if (*bookHeadPtr == NULL) {
            printf("\n");
        printf("\nEs sind keine Buecher im Inventar vorhanden.");
        return head;
    }

    printBookList(*bookHeadPtr);

    int bookNumber;
    char name[32];
    int count = 0;
    int validInput = 0;

    // count the number of books
    struct bookNode* currentBookCount = *bookHeadPtr;
    while (currentBookCount != NULL) {
        count++;
        currentBookCount = currentBookCount->next;
    }
    while(validInput < 1) { // i tried this validInput against the endlosschleife
    do {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", count);
        scanf(" %d", &bookNumber);
        if (bookNumber < 1 || bookNumber > count) {
            printf("\nUngueltige Eingabe!");
        }
    } while (bookNumber < 1 || bookNumber > count);

    struct bookNode* selectedBook = findBookByIndex(*bookHeadPtr, bookNumber);
    if (selectedBook == NULL) {
        printf("\nUngueltige Eingabe!");
        return head;
    }

    printf("\nGeben Sie Ihren Namen ein: ");
    scanf("%s", name);

    struct borrowNode* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->title, selectedBook->content.title) == 0 &&
            strcmp(temp->name, name) == 0) {

            printf("\nSie haben diesen Titel bereits ausgeliehen!");
            return head;
        }
        temp = temp->next;
    }


    if (selectedBook->content.amount > 0) {
        selectedBook->content.amount--;
        struct borrowNode* newNode = createBorrowNode(selectedBook->content.title, name);
        newNode->next = head;
        return newNode;
    } else {
        printf("\nBereits alle Exemplare ausgeliehen!");
        return head;
    }
}
    return head;
}

struct borrowNode* returnBook(struct borrowNode* head, struct bookNode** bookHead) {
    if (head == NULL) {
            printf("\n");
        printf("\nEs sind keine Titel ausgeliehen!");
        return NULL;
    }

    printBorrowList(head);

    int borrowNumber;
    int count = 0;
    int validInput = 0;

    // count the borrowed boooks
    struct borrowNode* currentBorrowCount = head;
    while (currentBorrowCount != NULL) {
        count++;
        currentBorrowCount = currentBorrowCount->next;
    }
    while(validInput < 1) {
    do {
        printf("\nWelchen Titel moechten Sie retournieren? (1-%d):  ", count);
        scanf(" %d", &borrowNumber);
        if (borrowNumber < 1 || borrowNumber > count) {
            printf("\nUngueltige Eingabe!");
        }
    } while (borrowNumber < 1 || borrowNumber > count);

    struct borrowNode* current = head;
    struct borrowNode* prev = NULL;
    int currentIndex = 1;

    while (current != NULL) {
        if (currentIndex == borrowNumber) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            struct bookNode* currentBook = *bookHead;
            while (currentBook != NULL) {
                if (strcmp(currentBook->content.title, current->title) == 0) {
                    currentBook->content.amount++;
                    break;
                }
                currentBook = currentBook->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
        currentIndex++;
    }
}
    return head;
}

void swap(struct bookNode* a, struct bookNode* b) {
    struct book temp = a->content;
    a->content = b->content;
    b->content = temp;
}

struct bookNode* copyBookList(struct bookNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct bookNode* newHead = createBookNode(head->content);
    struct bookNode* current = head->next;
    struct bookNode* newCurrent = newHead;

    while (current != NULL) {
        newCurrent->next = createBookNode(current->content);
        newCurrent = newCurrent->next;
        current = current->next;
    }

    return newHead;
}
void freeBookList(struct bookNode* head) {
    while (head != NULL) {
        struct bookNode* temp = head;
        head = head->next;
        free(temp);
    }
}
void freeBorrowList(struct borrowNode* head) {
    while (head != NULL) {
        struct borrowNode* temp = head;
        head = head->next;
        free(temp);
    }
}
void printListInOrder(struct bookNode* head) {
    struct bookNode* sortedList = copyBookList(head);
    int swapped;
    struct bookNode* temp;
    struct bookNode* last = NULL;

    if (sortedList == NULL) {
        return;
    }

    do {
        swapped = 0;
        temp = sortedList;

        while (temp->next != last) {
            if (temp->content.year > temp->next->content.year) {
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        last = temp;
    } while (swapped);

    printBookList(sortedList);
    freeBookList(sortedList);
}

int main() {
    struct bookNode* bookHead = NULL;
    struct borrowNode* borrowHead = NULL;
    int validInput = 0;
    char choice;

    while (validInput < 1) {   //funktioniert immer noch nicht, wenn man mehrere nicht valide buchstaben eingibt, wird es so oft angezeigt
        do {
            printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");
            scanf(" %c", &choice);

            switch (choice) {
                case 'n':
                    bookHead = insertBook(bookHead);
                    break;
                case 'b':
                    borrowHead = borrowBook(borrowHead, &bookHead);
                    break;
                case 'r':
                    borrowHead = returnBook(borrowHead, &bookHead);
                    break;
                case 'l':
                    printBookList(bookHead);
                    break;
                case 's':
                    printListInOrder(bookHead);
                    break;
                case 'x':
                    freeBookList(bookHead);
                    freeBorrowList(borrowHead);
                    validInput = 1; // Exit the loop
                    break;
                default:
                    printf("\nUngueltige Eingabe!");
            }
        } while (choice != 'x');
    }

    return 0;
}
