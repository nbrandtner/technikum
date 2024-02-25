#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition des Genres als Enumeration
typedef enum {
    Horror,
    Abenteuer,
    Romantik,
    Sachbuch
} genre_type;

// Struktur für ein Buch
typedef struct {
    char title[32]; // Titel des Buches
    genre_type genre; // Genre des Buches
    int year; // Erscheinungsjahr des Buches
    int amount; // Anzahl der Exemplare des Buches
} book;

// Knoten für die verkettete Liste der Bücher
typedef struct bookNode {
    book content; // Inhalt des Knotens (ein Buch)
    struct bookNode *next; // Zeiger auf den nächsten Knoten in der Liste
} bookNode;

// Struktur für ein ausgeliehenes Buch
typedef struct {
    char title[32]; // Titel des ausgeliehenen Buches
    char name[32]; // Name der Person, die das Buch ausgeliehen hat
} borrow;

// Knoten für die verkettete Liste der ausgeliehenen Bücher
typedef struct borrowedNode {
    borrow content; // Inhalt des Knotens (ein ausgeliehenes Buch)
    struct borrowedNode *next; // Zeiger auf den nächsten Knoten in der Liste
} borrowNode;

// Funktionen deklarieren
int getLength(bookNode *inventory) {
    int length = 0;
    bookNode *current = inventory;
    // Durch die Liste gehen und die Anzahl der Knoten zählen
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}
// Genre-Strings für die Ausgabe
const char *genreStrings[] = {"Horror", "Abenteuer", "Romantik", "Sachbuch"};

int getLengthBorrowed(borrowNode *borrowed) {
    int length = 0;
    borrowNode *current = borrowed;
    // Durch die Liste gehen und die Anzahl der Knoten zählen
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}
void freeList(bookNode **inventory) {
    bookNode *current = *inventory;
    // Durch die Liste gehen und jeden Knoten freigeben
    while (current != NULL) {
        bookNode *next = current->next;
        free(current);
        current = next;
    }
    *inventory = NULL;
}
void freeBorrowedList(borrowNode **borrowed) {
    borrowNode *current = *borrowed;
    // Durch die Liste gehen und jeden Knoten freigeben
    while (current != NULL) {
        borrowNode *next = current->next;
        free(current);
        current = next;
    }
}
    int *borrowed = NULL;
bookNode *getBook(bookNode *inventory, int index) {
    bookNode *current = inventory;
    // Durch die Liste gehen und das Buch mit dem angegebenen Index finden
    for (int i = 1; i < index; i++) {
        current = current->next;
    }
    return current;
}
bookNode *findBook(bookNode **inventory, char *title) {
    bookNode *current = *inventory;
    // Durch die Liste gehen und das Buch mit dem angegebenen Titel finden
    while (current != NULL) {
        if (strcmp(current->content.title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
borrowNode *removeBorrowed(borrowNode **borrowed, int index) {
    borrowNode *current = *borrowed;
    // Den ersten Knoten entfernen
    if (index == 1) {
        *borrowed = current->next;
        return current;
    }
    // Den Knoten mit dem angegebenen Index finden
    for (int i = 1; i < index - 1; i++) {
        current = current->next;
    }
    // Den Knoten entfernen
    borrowNode *removed = current->next;
    current->next = removed->next;
    return removed;
}
int isBorrowed(borrowNode *borrowed, char *title, char *name) {
    borrowNode *current = borrowed;
    // Durch die Liste gehen und überprüfen, ob das Buch mit dem angegebenen Titel bereits ausgeliehen wurde
    while (current != NULL) {
        if (strcmp(current->content.title, title) == 0 && strcmp(current->content.name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void printBorrowed(borrowNode *borrowed) {
    borrowNode *current = borrowed;
    int cnt = 1;
    // Durch die Liste gehen und jedes Buch ausgeben
    while (current != NULL) {
        printf("\n%d: %s geliehen von %s",cnt++, current->content.title, current->content.name);
        current = current->next;
    }
    printf("\n");
}
void insertBook(bookNode **inventory);
void printList(bookNode *inventory);
void borrowBook(bookNode **inventory, borrowNode **borrowed);
void returnBook(bookNode **inventory, borrowNode **borrowed);

// Funktion zum Einfügen eines neuen Buches in die Liste
void insertBook(bookNode **inventory) {
    // Speicher für einen neuen Knoten reservieren
    bookNode *newBookNode = (bookNode *)malloc(sizeof(bookNode));
    // Eingabeaufforderungen für die Buchdetails
    printf("\nGeben Sie den Titel ein: ");
    scanf(" %31s", newBookNode->content.title);
    do {
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        scanf("%d", (int *)&newBookNode->content.genre);
        if (newBookNode->content.genre < 1 || newBookNode->content.genre > 4) {
            printf("\nUngueltige Eingabe!");
        }
    } while (newBookNode->content.genre < 1 || newBookNode->content.genre > 4);
    do {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        scanf("%d", &newBookNode->content.year);
        if (newBookNode->content.year < 1 || newBookNode->content.year > 2023) {
            printf("\nUngueltige Eingabe!");
        }
    } while (newBookNode->content.year < 1 || newBookNode->content.year > 2023);
    do {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        scanf("%d", &newBookNode->content.amount);
        if (newBookNode->content.amount < 1) {
            printf("\nUngueltige Eingabe!");
        }
    } while (newBookNode->content.amount < 1);
    // Das neue Buch vorne an die Liste anfügen
    newBookNode->next = *inventory;
    *inventory = newBookNode;
}
// Funktion zum Ausgeben der Liste der Bücher
void printList(bookNode *inventory) {
    bookNode *current = inventory;
    int cnt = 1;
    // Durch die Liste gehen und jedes Buch ausgeben
    while (current != NULL) {
        printf("\n%d: %s, %s (%d)", cnt++, current->content.title, genreStrings[current->content.genre - 1], current->content.year);
        current = current->next;
    }
    printf("\n");
}
// Funktion zum Sortieren der Liste nach dem Erscheinungsjahr
void sortListByYear(bookNode **inventory) {
    int swapped;
    bookNode *ptr1;
    bookNode *lptr = NULL;

    // Check für leere Liste
    if (*inventory == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *inventory;

        while (ptr1->next != lptr) {
            if (ptr1->content.year > ptr1->next->content.year) {
                // Tausch der Bücher
                book temp = ptr1->content;
                ptr1->content = ptr1->next->content;
                ptr1->next->content = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
// Funktion zum Ausgeben der sortierten Liste der Bücher nach dem Erscheinungsjahr
void printListInOrder(bookNode *inventory) {
    // Sortiere die Liste nach dem Erscheinungsjahr
    sortListByYear(&inventory);

    // Gib die sortierte Liste aus
    printList(inventory);
}
// Funktion zum Ausleihen eines Buches
void borrowBook(bookNode **inventory, borrowNode **borrowed) {
    if (*inventory == NULL) {
        printf("\n\nEs sind keine Buecher im Inventar vorhanden.");
        return;
    }
    printList(*inventory);
    int choice;
    do {
        printf("\nWelchen Titel moechten Sie leihen? (1-%d):", getLength(*inventory));
        scanf("%d", &choice);
        // Überprüfen, ob die Eingabe gültig ist
        if (choice < 1 || choice > getLength(*inventory)) {
            printf("\nUngueltige Eingabe!");
        }
    } while (choice < 1 || choice > getLength(*inventory));
    // Das ausgewählte Buch finden
    bookNode *selectedBook = getBook(*inventory, choice);

    char name[32];
    printf("\nGeben Sie Ihren Namen ein: ");
    scanf("%s", name);
    if (selectedBook->content.amount == 0) {
        printf("\nBereits alle Exemplare ausgeliehen!");
        return;
    }
    // Überprüfen, ob der Benutzer dieses Buch bereits ausgeliehen hat
    if (isBorrowed(*borrowed, selectedBook->content.title, name)) {
        printf("\nSie haben diesen Titel bereits ausgeliehen!");
        return;
    }
    // Das Buch zur Liste der ausgeliehenen Bücher hinzufügen
    borrowNode *newBorrowNode = (borrowNode *)malloc(sizeof(borrowNode));
    strcpy(newBorrowNode->content.title, selectedBook->content.title);
    strcpy(newBorrowNode->content.name, name);
    newBorrowNode->next = *borrowed;
    *borrowed = newBorrowNode;
    // Die Anzahl der verfügbaren Exemplare des Buches verringern
    selectedBook->content.amount--;
}

// Funktion zum Zurückgeben eines Buches
void returnBook(bookNode **inventory, borrowNode **borrowed) {
    if (*borrowed == NULL) {
        printf("\n\nEs sind keine Titel ausgeliehen!");
        return;
    }
    printBorrowed(*borrowed);
    int choice;
    printf("\nWelchen Titel moechten Sie retournieren? (1-%d):", getLengthBorrowed(*borrowed));
    scanf("%d", &choice);
    // Überprüfen, ob die Eingabe gültig ist
    if (choice < 1 || choice > getLengthBorrowed(*borrowed)) {
        printf("\nUngueltige Eingabe!");
        return;
    }
    // Den ausgewählten Eintrag aus der Liste der ausgeliehenen Bücher entfernen
    borrowNode *returned = removeBorrowed(borrowed, choice);
    // Die Anzahl der verfügbaren Exemplare des zurückgegebenen Buches erhöhen
    bookNode *returnedBook = findBook(inventory, returned->content.title);
    returnedBook->content.amount++;
    // Den Speicher für den zurückgegebenen Eintrag freigeben
    free(returned);
}

// Hauptfunktion
int main() {
    char choice;
    bookNode *inventory = NULL; // Anfang der Bücherliste
    borrowNode *borrowed = NULL; // Anfang der Liste der ausgeliehenen Bücher
    do {
        // Menü anzeigen
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");
        scanf(" %c", &choice);
        switch (choice) {
            case 'n':
                // Neues Buch eingeben
                insertBook(&inventory);
                break;
            case 'b':
                // Buch ausleihen
                borrowBook(&inventory, &borrowed);
                break;
            case 'r':
                // Buch zurückgeben
                returnBook(&inventory, &borrowed);
                break;
            case 'l':
                // Liste der Bücher ausgeben
                printList(inventory);
                break;
            case 's':
                // Liste der Bücher sortieren
                printListInOrder(inventory);
                break;
            case 'x':
                // Programm beenden
                break;
            default:
                // Ungültige Eingabe
                printf("\nUngueltige Eingabe!");
        }
    } while (choice != 'x');
    // Den Speicher für die Listen freigeben
    freeList(&inventory);
    freeBorrowedList(&borrowed);
    return 0;
}