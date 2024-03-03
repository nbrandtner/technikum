/* aufgabe
Neues Buch eingeben (insertBook)
Buch ausleihen (borrowBook)
Buch zurückgeben (returnBook)
Bücher auflisten (printList)
Bücher sortiert ausgeben (printListInOrder)
Das Programm kann aus dem Menü mit der Eingabe x beendet werden.
Geben Sie Zeilenumbrüche immer vor einer neuen Zeile aus und nicht am Ende. Wenn Sie sich daran halten, sollte die Formatierung leichter zur Übereinstimmung mit der erwarteten Ausgabe gebracht werden können. Das Programm startet daher auch mit einem Zeilenumbruch.
In CodeRunner wird jede einzelne Eingabe von einem Zeilenumbruch bestätigt, der in der Ausgabe aber nicht sichtbar ist. Wenn Sie außerhalb von CodeRunner das Programm starten, selber Werte eingeben (siehe Beispielausgabe) und dabei Zeilenumbrüche produzieren, wirkt sich das auf die Ausgabe aus (mehr Zeilenumbrüche als beim automatischen Testen in CodeRunner).
Achten Sie darauf den Speicher korrekt zu verwalten, also alle Heapallokationen wieder freizugeben.
Das Verwenden von globalen Variablen ist nicht erlaubt!*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeration für genres
enum genre_type{
    Horror = 1,
    Abenteuer,
    Romantik,
    Sachbuch
};

// struct für ein Buch
struct book{
    char title[32];
    enum genre_type genre;
    int year;
    int amount;
};

// struct für einen Buchknoten in Inventarliste
struct bookNode {
    struct book content;
    struct bookNode *next;
};

// struct für einen Ausleihknoten in Liste der borrowed books
struct borrowNode {
    char title[32];
    char name[32];
    struct borrowNode *next;
};

// hier sind die funktionen very nice
void insertBook(struct bookNode **inventory);
void borrowBook(struct bookNode **inventory, struct borrowNode **borrowed);
void returnBook(struct borrowNode **borrowed);
void printList(struct bookNode *inventory);
void printListInOrder(struct bookNode *inventory);
void freeMemory(struct bookNode *inventory, struct borrowNode *borrowed);
int countBooks(struct bookNode *inventory);

int main() {
    char choice;
    struct bookNode *inventory = NULL;
    struct borrowNode *borrowed = NULL;

    do {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                insertBook(&inventory);
                break;
            case 'b':
                borrowBook(&inventory, &borrowed);
                break;
            case 'r':
                returnBook(&borrowed);
                break;
            case 'l':
                printList(inventory);
                break;
            case 's':
                printListInOrder(inventory);
                break;
            case 'x':
                break;
            default:
                printf("\nUngueltige Eingabe!");
        }
    } while (choice != 'x');

    // freigabe memory
    freeMemory(inventory, borrowed);

    return 0;
}

// funktion zum inserten eines neuen Buchs in Inventarliste
void insertBook(struct bookNode **inventory) {
    struct book newBook;

    printf("\nGeben Sie den Titel ein: ");
    scanf("%31s", newBook.title);

    int genreChoice;
    do {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf("%d", &genreChoice);

        if (genreChoice < 1 || genreChoice > 4) {
            printf("\nUngueltige Eingabe!");
        }
    } while (genreChoice < 1 || genreChoice > 4);

    newBook.genre = (enum genre_type)genreChoice;

    do {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf("%d", &newBook.year);

        if (newBook.year <= 0) {
            printf("\nUngueltige Eingabe!");
        }
    } while (newBook.year <= 0);

    do {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", &newBook.amount);

        if (newBook.amount <= 0) {
            printf("\nUngueltige Eingabe!");
        }
    } while (newBook.amount <= 0);

    // create einen neuen Buchknoten und add zur Inventarliste
    struct bookNode *newNode = (struct bookNode *)malloc(sizeof(struct bookNode));
    newNode->content = newBook;
    newNode->next = *inventory;
    *inventory = newNode;
}


// funktion to count anzahl der Bücher im Inventar
int countBooks(struct bookNode *inventory) {
    int count = 0;
    while (inventory != NULL) {
        count++;
        inventory = inventory->next;
    }
    return count;
}

// funktion zum ausleihen eines Buchs
void borrowBook(struct bookNode **inventory, struct borrowNode **borrowed) {
    if (*inventory == NULL) {
        printf("\n\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }

    printList(*inventory);

    int choice;
    do {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d): ", countBooks(*inventory));
        scanf("%d", &choice);

        // check gültigkeit des inputs
        if (choice < 1 || choice > countBooks(*inventory)) {
            printf("\nUngueltige Eingabe!");
        }
    } while (choice < 1 || choice > countBooks(*inventory));

    char borrowerName[32];
    printf("\nGeben Sie Ihren Namen ein: ");
    scanf("%s", borrowerName);

    // check ob der user das Buch schon ausgeliehen hat
    struct bookNode *currentBook = *inventory;
    for (int i = 1; i < choice; i++) {
        currentBook = currentBook->next;
    }

    struct borrowNode *currentBorrowed = *borrowed;
    while (currentBorrowed != NULL) {
        if (strcmp(currentBorrowed->title, currentBook->content.title) == 0 &&
            strcmp(currentBorrowed->name, borrowerName) == 0) {
            printf("\nSie haben diesen Titel bereits ausgeliehen!");
            return;
        }
        currentBorrowed = currentBorrowed->next;
    }

    // check ob alle Exemplare des Buchs ausgeliehen sind
    if (currentBook->content.amount == 0) {
        printf("\nBereits alle Exemplare ausgeliehen!");
        return;
    }

    // reduzieren der Anzahl verfügbarer Exemplare
    currentBook->content.amount--;

    // add ausgeliehenes Buch zur Liste
    struct borrowNode *newborrowNode = (struct borrowNode *)malloc(sizeof(struct borrowNode));
    strcpy(newborrowNode->title, currentBook->content.title);
    strcpy(newborrowNode->name, borrowerName);
    newborrowNode->next = *borrowed;
    *borrowed = newborrowNode;
}


// funktion zum returnen eines Buchs
void returnBook(struct borrowNode **borrowed) {
    if (*borrowed == NULL) {//keine ausgeliehenen titel
        printf("\n\nEs sind keine Titel ausgeliehen!");
        return;
    }

    struct borrowNode *currentBorrowed = *borrowed;
    int i = 1;
    while (currentBorrowed != NULL) {
        printf("\n%d: %s geliehen von %s", i, currentBorrowed->title, currentBorrowed->name);
        currentBorrowed = currentBorrowed->next;
        i++;
    }
    printf("\n");


    int choice;
    printf("\nWelchen Titel moechten Sie retournieren? (1-%d): ", i - 1);
    scanf("%d", &choice);

    // check gültigkeit des inputs
    if (choice < 1 || choice > i - 1) {
        printf("\nUngueltige Eingabe!");
        return;
    }

    // entfernen des zurückgegebenen Buchs aus liste der borrowed Books
    struct borrowNode *prevBorrowed = NULL;
    currentBorrowed = *borrowed;
    for (int j = 1; j < choice; j++) {
        prevBorrowed = currentBorrowed;
        currentBorrowed = currentBorrowed->next;
    }

    // remove Knoten aus der Liste
    if (prevBorrowed == NULL) {
        *borrowed = currentBorrowed->next;
    } else {
        prevBorrowed->next = currentBorrowed->next;
    }

    // free memory des zurückgegebenen Buchknotens
    free(currentBorrowed);

}
// funktion zum ausgeben einer liste aller Bücher im Inventar
void printList(struct bookNode *inventory) {
    int i = 1;
    while (inventory != NULL) {
        printf("\n%d: %s, ", i, inventory->content.title);
        switch (inventory->content.genre) {
            case Horror:
                printf("Horror");
                break;
            case Abenteuer:
                printf("Abenteuer");
                break;
            case Romantik:
                printf("Romantik");
                break;
            case Sachbuch:
                printf("Sachbuch");
                break;
        }
        printf(" (%d)", inventory->content.year);
        inventory = inventory->next;
        i++;
    }
    printf("\n");

}

// funktion zum ausgeben der nach dem erscheinungsjahr sortierten liste
void printListInOrder(struct bookNode *inventory) {
    // crate and fill array mit den Büchern
    int count = 0;
    struct bookNode *current = inventory;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    struct book *booksArray = (struct book *)malloc(count * sizeof(struct book));
    current = inventory;
    for (int i = 0; i < count; i++) {
        booksArray[i] = current->content;
        current = current->next;
    }

    //nach dem erscheinungsjahr sortieren
   for (int i = 0; i < count - 1; i++) {
    for (int j = 0; j < count - i - 1; j++) {
        if (booksArray[j].year > booksArray[j + 1].year) {
            struct book temp = booksArray[j];
            booksArray[j] = booksArray[j + 1];
            booksArray[j + 1] = temp;
        }
    }
}

    // ausgabe der sortierten Liste
    for (int i = 0; i < count; i++) {
        printf("\n%d: %s, ", i + 1, booksArray[i].title);
        switch (booksArray[i].genre) {
            case Horror:
                printf("Horror");
                break;
            case Abenteuer:
                printf("Abenteuer");
                break;
            case Romantik:
                printf("Romantik");
                break;
            case Sachbuch:
                printf("Sachbuch");
                break;
        }
        printf(" (%d)", booksArray[i].year);
    }
    printf("\n");

    // freigabe des arrayspeichers
    free(booksArray);
}

// funktion zur freigabe vom memory
void freeMemory(struct bookNode *inventory, struct borrowNode *borrowed) {
    // Freigabe der Inventarliste
    while (inventory != NULL) {
        struct bookNode *temp = inventory;
        inventory = inventory->next;
        free(temp);
    }

    // Freigabe der Liste der ausgeliehenen Bücher
    while (borrowed != NULL) {
        struct borrowNode *temp = borrowed;
        borrowed = borrowed->next;
        free(temp);
    }
}
