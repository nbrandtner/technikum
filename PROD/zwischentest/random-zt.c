#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum genre {
    Horror = 1,
        Abenteuer,
        Romantik,
        Sachbuch
};

typedef struct book {
    char titel[32];
    enum genre buchGenre;
    int erscheinungsjahr;
    int exemplarenAnzahl;
}
book;

typedef struct booknode {
    book content;
    struct booknode * next;
}
booknode;

typedef struct borrowNode {
    char title[32];
    char name[32];
    struct borrowNode * next;
}
borrowNode;

void insertbook(booknode ** bookList) {
    book Book;
    int korrekteEingabe;
    printf("\nGeben Sie den Titel ein: ");
    scanf(" %s", Book.titel);
    do {
        korrekteEingabe = 0;
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf(" %d", (int * ) & (Book.buchGenre));
        if (Book.buchGenre <= 4 && Book.buchGenre >= 1) {
            korrekteEingabe = 1;
        } else {
            printf("\nUngueltige Eingabe!");
        }
    } while (korrekteEingabe == 0);

    korrekteEingabe = 0;

    do {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf("%d", & (Book.erscheinungsjahr));
        if (Book.erscheinungsjahr > 0) {
            korrekteEingabe = 1;
        } else {
            printf("\nUngueltige Eingabe!");
        }
    } while (korrekteEingabe == 0);

    korrekteEingabe = 0;
    do {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", & (Book.exemplarenAnzahl));
        if (Book.exemplarenAnzahl > 0) {
            korrekteEingabe = 1;
        } else {
            printf("\nUngueltige Eingabe!");
        }
    } while (korrekteEingabe == 0);
    korrekteEingabe = 0;
    booknode * newBook = (booknode * ) malloc(sizeof(booknode));
    newBook -> content = Book;
    newBook -> next = * bookList;
    * bookList = newBook;
}

int MaxBookCount(booknode * bookList) {
    int count = 0;
    while (bookList != NULL) {
        count++;
        bookList = bookList -> next;
    }
    return count;
}
int MaxBookCountBorrowed(borrowNode * borrowList) {
    int count = 0;
    while (borrowList != NULL) {
        count++;
        borrowList = borrowList -> next;
    }
    return count;
}

void printList(booknode * bookList) {
    int i = 1;
    while (bookList != NULL) {
        printf("\n%d:", i);
        printf(" %s,", bookList -> content.titel);
        switch (bookList -> content.buchGenre) {
        case 1:
            printf(" Horror");
            break;
        case 2:
            printf(" Abenteuer");
            break;
        case 3:
            printf(" Romantik");
            break;
        case 4:
            printf(" Sachbuch");
            break;
        default:
            break;
        }
        printf(" (%d)", bookList -> content.erscheinungsjahr);
        bookList = bookList -> next;
        i++;
    }
}

void borrowbook(booknode ** bookList, borrowNode ** borrowList) {
    if ( * bookList == NULL) {
        printf("\n");
        printf("\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }
    printList( * bookList);
    printf("\n");
    int korrekteEingabe;
    int eingabe;
    do {
        korrekteEingabe = 0;
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", MaxBookCount( * bookList));
        scanf(" %d", & eingabe);
        if (eingabe < 1 || eingabe > MaxBookCount( * bookList)) {
            printf("\nUngueltige Eingabe!");
        } else {
            korrekteEingabe = 1;
        }
    } while (korrekteEingabe == 0);
    korrekteEingabe = 0;

    char personName[32];
    printf("\nGeben Sie Ihren Namen ein: ");
    scanf(" %s", personName);
    //das buch finden, welches ausgeliehen werden sollte
    booknode * WantedBook = * bookList;
    for (int i = 1; i < eingabe; i++) {
        WantedBook = WantedBook -> next;
    }
    //überprüfen, ob das buch bereits der gleichen person ausgeliehen wurde.
    borrowNode * otherBooks = * borrowList;
    while (otherBooks != NULL) {
        if (strcmp(otherBooks -> title, WantedBook -> content.titel) == 0 && strcmp(otherBooks -> name, personName) == 0) {
            printf("\nSie haben diesen Titel bereits ausgeliehen!");
            return;
        }
        otherBooks = otherBooks -> next;
    }
    if (WantedBook -> content.exemplarenAnzahl == 0) {
        printf("\nBereits alle Exemplare ausgeliehen!");
        return;
    }
    borrowNode * newBorrowedBook = (borrowNode * ) malloc(sizeof(borrowNode));
    strcpy(newBorrowedBook -> title, WantedBook -> content.titel);
    strcpy(newBorrowedBook -> name, personName);
    newBorrowedBook -> next = * borrowList;
    * borrowList = newBorrowedBook;
    WantedBook -> content.exemplarenAnzahl--;
}
void returnBook(booknode ** bookList, borrowNode ** borrowList) {
    if ( * borrowList == NULL) {
        printf("\n");
        printf("\nEs sind keine Titel ausgeliehen!");
        return;
    }
    int count = 1;
    borrowNode * ReturnedBook = * borrowList;
    while (ReturnedBook != NULL) {
        printf("\n%d: %s geliehen von %s", count, ReturnedBook -> title, ReturnedBook -> name);
        ReturnedBook = ReturnedBook -> next;
        count++;
    }
    printf("\n");
    int eingabe;
    int korrekteEingabe;
    do {
        korrekteEingabe = 0;
        printf("\nWelchen Titel moechten Sie retournieren? (1-%d): ", MaxBookCountBorrowed( * borrowList));
        scanf(" %d", & eingabe);

        if (eingabe < 1 || eingabe > MaxBookCountBorrowed( * borrowList)) {
            printf("\nUngueltige Eingabe!");
        } else {
            korrekteEingabe = 1;
            break;
        }
    } while (korrekteEingabe == 0);
    korrekteEingabe = 0;

    borrowNode * previous = NULL;
    ReturnedBook = * borrowList;
    for (int i = 1; i < eingabe; i++) {
        previous = ReturnedBook;
        ReturnedBook = ReturnedBook -> next;
    }
    if (previous == NULL) {
        * borrowList = ReturnedBook -> next;
    } else {
        previous -> next = ReturnedBook -> next;
    }

    booknode * returnedBook = * bookList;
    while (returnedBook != NULL && strcmp(returnedBook -> content.titel, ReturnedBook -> title) != 0) {
        returnedBook = returnedBook -> next;
    }
    if (returnedBook != NULL) {
        returnedBook -> content.exemplarenAnzahl++;
        free(ReturnedBook);
    }
}

void bubbleSort(booknode ** bookList) {
    int PositionChanged;
    booknode * First;
    booknode * Last = NULL;

    do {
        PositionChanged = 0;
        First = * bookList;

        while (First -> next != Last) {
            if (First -> content.erscheinungsjahr > First -> next -> content.erscheinungsjahr) {
                book temp = First -> content;
                First -> content = First -> next -> content;
                First -> next -> content = temp;
                PositionChanged = 1;
            }
            First = First -> next;
        }
        Last = First;
    } while (PositionChanged == 0);
    printList( * bookList);
}

void freeBookList(booknode ** bookList) {
    while ( * bookList != NULL) {
        booknode * eachBook = * bookList;
        * bookList = ( * bookList) -> next;
        free(eachBook);
    }
}
void freeBorrowList(borrowNode ** borrowList) {
    while ( * borrowList != NULL) {
        borrowNode * eachBook = * borrowList;
        * borrowList = ( * borrowList) -> next;
        free(eachBook);
    }
}

int main() {
    booknode * bookList = NULL;
    borrowNode * borrowList = NULL;
    char eingabe;
    while (1) {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c", & eingabe);

        switch (eingabe) {
        case 'n':
            insertbook( & bookList);
            break;
        case 'b':
            borrowbook( & bookList, & borrowList);
            break;
        case 'r':
            returnBook( & bookList, & borrowList);
            break;
        case 'l':
            printList(bookList);
            printf("\n");
            break;
        case 's':
            bubbleSort( & bookList);
            printf("\n");
            break;
        case 'x':
            freeBookList( & bookList);
            freeBorrowList( & borrowList);
            return 0;
        default:
            printf("\nUngueltige Eingabe!");
            continue;
        }
    }
    return 0;
}
