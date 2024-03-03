#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define IS_STRING 0
#define IS_INT 1
#define IS_ENUM 2
#define IS_BORROW 3
#define IS_RETURN 4

typedef enum
{
    Horror = 1, Abenteuer, Romantik, Sachbuch
}Genre;

typedef struct
{

    char title[33];
    Genre genre;
    int year;
    int amount;
    char borrower[33];
} Book;

typedef struct
{
    //char name[33];
    struct node* borrowedBooks;
} User;

struct node
{
    Book newBook;
    struct node* next;
};

void startApplication();
void closeApplication(struct node* head);
void returnBook(struct node* bookInventory, User* user);
struct node* borrowBook(struct node* bookInventory, User* user, int index);
void listLibrary(struct node* head);
struct node* addBook(struct node* bookLibrary, struct node** bookInventory);
struct node* createNode(char* title, Genre newGenre, int year, int amount);
bool hasUserBorrowedBook(User* user, char* title);
const char* getGenreName(Genre genre);
void getUserInput(struct node* head, User* user, int* index, char* name, int flag);
void getBookDetails(char* title, Genre* genre, int* year, int* amount);

void getBookDetails(char* title, Genre* genre, int* year, int* amount)
{
    //clear cache to avoid blank insertion
    int c;
    bool isRunning = true;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("\nGeben Sie den Titel ein: ");
    fgets(title, 32, stdin); // read string
    title[strcspn(title, "\n")] = 0; // removes new line character that fgets reads

    do
    {
        int tempGenre;
        printf("\nGeben Sie das Genre ein. Horror (1), Abenteuer (2), Romantik (3), Sachbuch (4): ");
        if(scanf(" %d", &tempGenre) != 1 || tempGenre < Horror || tempGenre > Sachbuch)
        {
            printf("\nUngueltige Eingabe!");
            while(getchar() != '\n'); // Clear input buffer
        }
        else
        {
            *genre = tempGenre;
            break;
        }
    } while(isRunning);

    do
    {
        printf("\nGeben Sie das Erscheinungsjahr ein: ");
        if(scanf(" %d", year) != 1 || *year <= 0)
        {
            printf("\nUngueltige Eingabe!");
            while(getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while(isRunning);

    do
    {
        printf("\nGeben Sie ein wieviele Exemplare vorhanden sind: ");
        if(scanf(" %d", amount) != 1 || *amount <= 0) // Check if amount is greater than 0
        {
            printf("\nUngueltige Eingabe!");
            while(getchar() != '\n'); // Clear input buffer
        }
        else
        {
            break;
        }
    } while(isRunning);
}

struct node* getBorrowedBookByIndex(User* user, int index)
{
    int counter = 1;
    struct node* temp = user->borrowedBooks;
    while(temp != NULL)
    {
        if(counter == index)
        {
            return temp;
        }
        temp = temp->next;
        counter++;
    }
    return NULL;
}

void listBorrowedBooks(User* user) {
    struct node* temp = user->borrowedBooks;
    int counter = 1;

    while(temp != NULL)
    {
        printf("\n%d: %s geliehen von %s", counter++, temp->newBook.title, temp->newBook.borrower);
        temp = temp->next;
    }
    printf("\n");
}

void getUserInput(struct node* head, User* user, int* index, char* name, int flag)
{
    int bookCount = 0;
    bool isRunning = true;
    struct node* temp = head;
    while(temp != NULL)
    {
        bookCount++;
        temp = temp->next;
    }

    if(flag == IS_BORROW)
    {
        listLibrary(head);
        do
        {
            printf("\nWelchen Titel moechten Sie leihen? (1-%d):", bookCount);
            if(scanf("%d", index) != 1 || *index < 1 || *index > bookCount)
            {
                printf("\nUngueltige Eingabe!");
                while(getchar() != '\n'); // Clear input buffer
            }
            else
            {
                printf("\nGeben Sie Ihren Namen ein: ");
                scanf("%s", name);
                while(getchar() != '\n'); // Clear input buffer
                break;
            }
        } while(isRunning);
    }
    else if(flag == IS_RETURN)
    {
        listBorrowedBooks(user);
        int borrowedBookCount = 0;
        struct node* temp2 = user->borrowedBooks; // Rename this variable to avoid shadowing
        while(temp2 != NULL)
        {
            borrowedBookCount++;
            temp2 = temp2->next;
        }
        do
        {
            printf("\nWelchen Titel moechten Sie retournieren? (1-%d):", borrowedBookCount);
            if(scanf("%d", index) != 1 || *index < 1 || *index > borrowedBookCount)
            {
                printf("\nUngueltige Eingabe!");
                while(getchar() != '\n'); // Clear input buffer
            }
            else
            {
                while(getchar() != '\n'); // Clear input buffer
                break;
            }
        } while(isRunning);
    }
    else
    {
        printf("Unbekannter Befehl: %d", flag);
    }
}


const char* getGenreName(Genre genre)
{
    switch(genre)
    {
        case Horror: return "Horror";
        case Abenteuer: return "Abenteuer";
        case Romantik: return "Romantik";
        case Sachbuch: return "Sachbuch";
        default: return "Unknown Genre";
    }
}

bool hasUserBorrowedBook(User* user, char* title)
{
    struct node* temp = user->borrowedBooks;
    while(temp != NULL)
    {
        if(strcmp(temp->newBook.title, title) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

struct node* createNode(char* title, Genre newGenre, int year, int amount)
{

    // allocate memory
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    // copy book information to new node
    strncpy(newNode->newBook.title, title, sizeof(newNode->newBook.title));
    newNode->newBook.amount = amount;
    newNode->newBook.year = year;
    newNode->newBook.genre = newGenre;

    // node doesn't point to another node yet
    newNode->next = NULL;

    return newNode;
};

struct node* addBook(struct node* bookLibrary, struct node** bookInventory)
{
    char title[33];
    Genre genre;
    int year;
    int amount;
    getBookDetails(title, &genre, &year, &amount); // Initialize all book variables and get input from user

    struct node* newBook = createNode(title, genre, year, amount);
    if(newBook != NULL)
    {
        newBook->next = bookLibrary; //add book to library
        bookLibrary = newBook;

        struct node* inventoryBook = createNode(title, genre, year, amount); //add book to inventory for borrowing
        inventoryBook->next = *bookInventory;
        *bookInventory = inventoryBook;
    }

    return bookLibrary; //return bookLibrary to update the head pointer
}

void listLibrary(struct node* head)
{
    struct node* temp = head;
    int counter = 1;

    while(temp != NULL)
    {
        printf("\n%d: %s, %s (%d)", counter++, temp->newBook.title, getGenreName(temp->newBook.genre), temp->newBook.year);
        temp = temp->next;//move to next node
    }
    printf("\n");
}

struct node* borrowBook(struct node* bookInventory, User* user, int index) {
    int counter = 1;
    char name[33];
    struct node* temp = bookInventory;


    while (temp != NULL) {
        if (counter == index) {
            if(temp->newBook.amount <= 0){
                printf("\nBereits alle Exemplare ausgeliehen! ");
                return bookInventory;
            }else if(hasUserBorrowedBook(user, temp->newBook.title)){
                if (temp->newBook.amount <= 0) {
                    printf("\nBereits alle Exemplare ausgeliehen! ");
                    return bookInventory;
                }else{
                    temp->newBook.amount--; // Decrease the amount in the inventory

                    struct node* borrowedBook = createNode(temp->newBook.title, temp->newBook.genre, temp->newBook.year, 0);
                    strcpy(borrowedBook->newBook.borrower, name);
                    borrowedBook->next = user->borrowedBooks;
                    user->borrowedBooks = borrowedBook;
                }
                return bookInventory; // Returning bookInventory here to keep the function consistent
            }
            temp = temp->next;
            counter++;
        }

    printf("\nBook not found.");
    return bookInventory;
    }
}

void returnBook(struct node* bookInventory, User* user){
    int index;
    int counter = 1;
    char name[33];

    struct node* temp = user->borrowedBooks;
    struct node* prev = NULL;

    getUserInput(user->borrowedBooks, user, &index, name, IS_RETURN);

    while(temp != NULL)
    {
        if(counter == index) // If this is the book to return
        {
            // Find the book in the inventory and increase its amount
            struct node* inventoryTemp = bookInventory;
            while(inventoryTemp != NULL)
            {
                if(strcmp(inventoryTemp->newBook.title, temp->newBook.title) == 0) // If the titles match
                {
                    inventoryTemp->newBook.amount++; // Increase the amount in the inventory
                    break;
                }
                inventoryTemp = inventoryTemp->next;
            }

            struct node* nextNode = temp->next;
            if(prev == NULL)
            {
                user->borrowedBooks = nextNode;
            }
            else
            {
                prev->next = nextNode;
            }
            temp->next = NULL; // Set the next pointer of the current node to NULL

            free(temp);

            temp = nextNode;

            return; // Return after updating bookInventory
        }
        prev = temp;
        temp = temp->next;
        counter++;
    }
}

void closeApplication(struct node* head)
{
    struct node* temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Book* linkedListToArray(struct node* head, int* size)
{
    *size = 0;
    struct node* temp = head;
    while(temp != NULL)
    {
        (*size)++;
        temp = temp->next;
    }

    Book* array = malloc(*size * sizeof(Book));
    temp = head;
    for(int i = 0; i < *size; i++)
    {
        array[i] = temp->newBook;
        temp = temp->next;
    }

    return array;
}

void sortList(Book* array, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(array[j].year > array[j + 1].year)
            {
                Book temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void listPrinter(Book* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\n%d: %s, %s (%d)", i + 1, array[i].title, getGenreName(array[i].genre), array[i].year);
    }
    printf("\n");
}

void printSortedList(struct node* bookLibrary)
{
    int size;
    Book* bookList = linkedListToArray(bookLibrary, &size);
    sortList(bookList, size);
    listPrinter(bookList, size);
    free(bookList);
}

void startApplication()
{
    char userInput;
    bool isRunning = true;
    struct node* bookLibrary = NULL; //initialize the bookLibrary node
    struct node* bookInventory = NULL; //initialize the bookInventory node
    User user = {NULL}; //initialize the user

    while(isRunning)
    {
        printf("\nNeues Buch eingeben (n), Buch ausleihen (b), Buch zurueckgeben (r), Buecher auflisten (l), Buecher sortieren (s), Programm beenden (x)\nAuswahl: ");

        scanf(" %c", &userInput);
        switch(userInput)
        {
        case 'n': // add book
            bookLibrary = addBook(bookLibrary, &bookInventory);
            break;
        case 'b': // borrow book
            borrowBook(bookInventory, &user, 1);
            break;
        case 'r': // return book
            returnBook(bookInventory, &user);
            break;
        case 'l': // print list
            listLibrary(bookLibrary);
            break;
        case 's': // print sorted list
            printSortedList(bookLibrary);
            break;
        case 'x': // close application
            closeApplication(bookLibrary);
            closeApplication(bookInventory);
            closeApplication(user.borrowedBooks);
            isRunning = false;
            break;
        default:
            printf("\nUngueltige Eingabe!");
            break;
        }
    }
}

int main()
{
    startApplication();
    return 0;
}
