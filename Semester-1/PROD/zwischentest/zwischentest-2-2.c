#include <stdio.h>
#include <stdlib.h>

enum Type { Freunde, Geschaeftlich, Pause };

struct appointment {
    enum Type type;
    int time;
    int duration;
};

void printAppointments(struct appointment *schedule, int length) {
    for (int i = 0; i < length; i++) {
        printf("\n%d: ", i + 1);
        switch (schedule[i].type) {
            case Freunde:
                printf("Freunde: ");
                break;
            case Geschaeftlich:
                printf("Geschaeftlich: ");
                break;
            case Pause:
                printf("Pause: ");
                break;
        }
        printf("%d Uhr, Dauer %dh", schedule[i].time, schedule[i].duration);
    }
}

void printInformation(struct appointment *schedule, int length) {
    int collision = 0;
    for (int i = 0; i < length - 1; i++) {
        if (schedule[i].time + schedule[i].duration > schedule[i + 1].time) {
            collision = 1;
            printf("\nEntweder Termin %d oder Termin %d sollte abgesagt werden.", i + 1, i + 2);
        }
    }
    if (!collision) {
        printf("\nDer Kalender hat keine Kollisionen!");
    }

    for (int i = 0; i < length - 1; i++) {
            if (schedule[i].type != Pause && schedule[i + 1].type != Pause) {
                printf("\nZwischen Termin %d und %d wird eine Pause benoetigt.", i + 1, i + 2);
            }
        }


    int businessCount = 0, friendsCount = 0, pauseCount = 0;

    for (int i = 0; i < length; i++) {
        switch (schedule[i].type) {
            case Freunde:
                friendsCount++;
                break;
            case Geschaeftlich:
                businessCount++;
                break;
            case Pause:
                pauseCount++;
                break;
        }
    }

    printf("\nSie haben %d Geschaeftstermin(e), %d Termin(e) mit Freunden und %d Pause(n) in Ihrem Kalender.", businessCount, friendsCount, pauseCount);
}

struct appointment createAppointment() {
    struct appointment newAppointment;
    char typeInput;
    int timeInput, durationInput;


    int firstTime = 1;

    do {
        if(!firstTime)
        {
            printf("\nUngueltige Eingabe!");
        }
        firstTime = 0;
        printf("\nGib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): ");
        scanf(" %c", &typeInput);
    } while (typeInput != 'f' && typeInput != 'b' && typeInput != 'p');

    switch (typeInput) {
        case 'f':
            newAppointment.type = Freunde;
            break;
        case 'b':
            newAppointment.type = Geschaeftlich;
            break;
        case 'p':
            newAppointment.type = Pause;
            break;
    }

    firstTime = 1;
    do {

        if(!firstTime){
            printf("\nUngueltige Eingabe!");
        }
        firstTime = 0;
        printf("\nGib eine Uhrzeit ein (8-21): ");
        scanf("%d", &timeInput);
    } while (timeInput < 8 || timeInput > 21);

    newAppointment.time = timeInput;


    int maxDurationInput = 22-timeInput;

    firstTime = 1;
    do {
        if(!firstTime)
        {
            printf("\nUngueltige Eingabe!");
        }
        firstTime = 0;
        printf("\nGib eine Dauer ein (1-%d): ",maxDurationInput);
        scanf("%d", &durationInput);
    } while (durationInput < 1 || durationInput > 14);

    newAppointment.duration = durationInput;

    return newAppointment;
}

void addAppointment(struct appointment *schedule, int *length) {
    if (*length == 10) {
        printf("Der Kalender ist voll!\n");
        return;
    }

    struct appointment newAppointment = createAppointment();

    int index = *length;

    while (index > 0 && schedule[index - 1].time > newAppointment.time) {
        schedule[index] = schedule[index - 1];
        index--;
    }

    schedule[index] = newAppointment;
    (*length)++;
}

void deleteAppointment(struct appointment *schedule, int *length) {
    if (*length == 0) {
        printf("\nDer Kalender ist leer!");
        return;
    }

    printAppointments(schedule, *length);

    int indexToDelete;
    int firstTime = 1;
    do {
        if(firstTime){
            printf("\nWelchen dieser Termine moechten Sie loeschen? (1-%d): ", *length);
            firstTime = 0;
        }
        else{
             printf("Ungueltige Eingabe!");
        }

        scanf("%d", &indexToDelete);
    } while (indexToDelete < 1 || indexToDelete > *length);

    for (int i = indexToDelete - 1; i < *length - 1; i++) {
        schedule[i] = schedule[i + 1];
    }

    (*length)--;
    printf("\nTermin %d wurde geloescht!", indexToDelete);
}


int main() {
    struct appointment schedule[10];
    int length = 0;
    char choice;

    while (1) {


        printf("\nNeuen Termin (n), Termin loeschen (d), Termine auflisten (l), Informationen ausgeben (i), Programm beenden (x)");
        printf("\nAuswahl: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'n':
                addAppointment(schedule, &length);
                break;
            case 'd':
                deleteAppointment(schedule, &length);
                break;
            case 'l':
                printAppointments(schedule, length);
                break;
            case 'i':
                printInformation(schedule, length);
                break;
            case 'x':
                return 0;
            default:
                printf("\nUngueltige Eingabe!");
        }
    }

    return 0;
}
