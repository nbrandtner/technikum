#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ich hatte leider zu wenig Zeit, um alle Funktionen zu implementieren, deswegen habe ich weder
//die Funktion borrowBook noch die Funktion returnBook gemacht. :c

enum genre_type {
    Horror = 1,
    Abenteuer,
    Romantik,
    Sachbuch
};

struct book {
    char title[33];
    enum genre_type genre;
    int year;
    int amount;
};

//Linked list for books
struct bookNode {
    struct book content;
    struct bookNode *next;
};

//Linked list for people borrowing books
//struct borrowNode {
//   char name[33];
//    struct borrowNode* next;
//};

struct bookNode* createBookNode(char* new_title, int new_genre, int new_year, int new_amount) {

    //Speicherplatz zuweisen mit malloc
    struct bookNode *newNode = (struct bookNode *)malloc(sizeof(struct bookNode));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Copy new_title into the new node
    strcpy(newNode->content.title, new_title);

    newNode->content.genre = new_genre;
    newNode->content.year = new_year;
    newNode->content.amount = new_amount;
    newNode->next = NULL;

    return newNode;
}

//Press N
void insertBook(struct bookNode** bookHead) {

    char new_title[33]="";
    int new_genre=0;
    int new_year=0;
    int new_amount=0;

    //Verify inputs

    //Check title
    while(1) {
        printf("\nGeben Sie den Titel ein: ");
        scanf(" %31s", new_title);

        if(strlen(new_title) > 32) {
            printf("\nUngueltige Eingabe!");
        } else {
            break;
        }
    }

    //Check genre
    while(1) {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf("%d", &new_genre);

        if(new_genre < 1 || new_genre > 4) {
            printf("\nUngueltige Eingabe!");
        } else {
            break;
        }
    }

    //Check year
    while(1) {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf("%d", &new_year);

        if(new_year <= 0) {
            printf("\nUngueltige Eingabe!");
        } else {
            break;
        }
    }

    //Check amount
    while(1) {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", &new_amount);

        if(new_amount <= 0) {
            printf("\nUngueltige Eingabe!");
        } else {
            break;
        }
    }

    //If every input is valid, the new book is created as a part of the linked list
    struct bookNode* newNode = createBookNode(new_title, new_genre, new_year, new_amount);

    newNode->next = *bookHead;
    *bookHead = newNode;
}

//Press L
void printList(struct bookNode** bookHead, int bookAmount) {

    //Make a new pointer (current) to point to each book
    struct bookNode* current = *bookHead;

    for(int i = 0; i < bookAmount; i++) {
        printf("\n%d: %s, ", i+1, current->content.title);

        switch(current->content.genre) {
            case 1:
                printf("Horror ");
                break;
            case 2:
                printf("Abenteuer ");
                break;
            case 3:
                printf("Romantik ");
                break;
            case 4:
                printf("Sachbuch ");
                break;
        }

        printf("(%d)", current->content.year);

        //Go to next book
        current = current->next;
    }

}

void swap(struct bookNode** a, struct bookNode** b) {
    struct bookNode* temp = *a;
    *a = *b;
    *b = temp;
}

//Press S
void printListInOrder(struct bookNode** bookHead, int bookAmount) {
    struct bookNode** array = malloc(bookAmount * sizeof(struct bookNode));

    struct bookNode* current = *bookHead;

    //Save all info of books in array
    for(int i = 0; i < bookAmount; i++) {
        array[i] = current;
        current = current->next;
    }

    //Bubble sort
    for(int i = 0; i < bookAmount - 1; i++) {
        for(int j = 0; j < bookAmount - 1; j++) {
            if(array[j]->content.year > array[j+1]->content.year) {
                swap(&array[j], &array[j+1]);
            }
        }
    }

    free(array);
}

int main()
{
    struct bookNode* bookHead = NULL;
    //struct borrowNode* borrowHead = NULL;
    char auswahl;
    int bookAmount = 0;

    while(1) {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");
        scanf(" %c", &auswahl);

        switch(auswahl)
        {
            case 'n':
                insertBook(&bookHead);
                bookAmount++;
                break;
            case 'l':
                printList(&bookHead, bookAmount);
                break;
            case 's':
                printListInOrder(&bookHead, bookAmount);
                break;
            case 'x':
                struct bookNode *tempBook;
                struct borrowNode *tempBorrow;
                while (bookHead != NULL) {
                    tempBook = bookHead;
                    bookHead = bookHead->next;
                    free(tempBook);
                }
                //while (headBorrow != NULL) {
                //    tempborrow = headBorrow;
                //    headBorrow = headBorrow->next;
                //    free(tempborrow);
                //}
                return 0;
            default:
                printf("\nUngueltige Eingabe!");
        }
    }


    return 0;
}
