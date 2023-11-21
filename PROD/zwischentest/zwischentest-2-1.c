#include <stdio.h>

enum Type{
    FREUNDE='f',
    GESCHAEFTLICH='b',
    PAUSE='p'
};

struct Appointment{
    enum Type type;
    int begin;
    int duration;
};

void printAppointments(struct Appointment * schedule, int length){
    for(int i=0;i<length;++i){
        printf("\n%d: ",i+1);
        switch(schedule[i].type){
            case FREUNDE:
                printf("Freunde");
                break;
            case GESCHAEFTLICH:
                printf("Geschaeftlich");
                break;
            case PAUSE:
                printf("Pause");
                break;
        }
        printf(": %d Uhr, Dauer %dh", schedule[i].begin, schedule[i].duration);
    }
}

void printInformation(struct Appointment * schedule, int length){
    int collision=0;
    int businessCount=0, friendsCount=0, pauseCount=0;
    for(int i=0;i<length-1;++i){
        if((schedule[i].begin+schedule[i].duration)>schedule[i+1].begin){
            collision=1;
            printf("\nEntweder Termin %d oder Termin %d sollte abgesagt werden.", i+1, i+2);
            break;
        }
    }
    if(!collision){
        printf("\nDer Kalender hat keine Kollisionen!");
        for(int i=0;i<length-1;++i){
            if(schedule[i].type != PAUSE && schedule[i+1].type != PAUSE){
                if((schedule[i].begin+schedule[i].duration)!=schedule[i+1].begin || (schedule[i].type==GESCHAEFTLICH&&schedule[i+1].type==GESCHAEFTLICH)
                || (schedule[i].type==GESCHAEFTLICH&&schedule[i+1].type==FREUNDE) || (schedule[i].type==FREUNDE&&schedule[i+1].type==GESCHAEFTLICH)){
                    printf("\nZwischen Termin %d und %d wird eine Pause benoetigt.", i+1, i+2);
                }
            }
        }
    }
    for(int i=0; i<length; ++i){
        switch(schedule[i].type){
            case FREUNDE:
                friendsCount++;
                break;
            case GESCHAEFTLICH:
                businessCount++;
                break;
            case PAUSE:
                pauseCount++;
                break;
        }
    }
    printf("\nSie haben %d Geschaeftstermin(e), %d Termin(e) mit Freunden und %d Pause(n) in Ihrem Kalender.", businessCount, friendsCount, pauseCount);
}

struct Appointment createAppointment(){
    struct Appointment newAppointment;
    char typeChar;
    printf("\nGib einen Typen ein: Freunde (f), Geschaeftlich (b), Pause (p): ");
    scanf(" %c", &typeChar);
    switch(typeChar){
        case FREUNDE:
            newAppointment.type=FREUNDE;
            break;
        case GESCHAEFTLICH:
            newAppointment.type=GESCHAEFTLICH;
            break;
        case PAUSE:
            newAppointment.type=PAUSE;
            break;
        default:
            printf("\nUngueltige Eingabe!");
            return createAppointment();
    }
    do{
        printf("\nGib eine Uhrzeit ein (8-21): ");
        scanf("%d", &newAppointment.begin);
        if(newAppointment.begin<8||newAppointment.begin>21){
            printf("\nUngueltige Eingabe!");
            continue;
        }
    }while(newAppointment.begin<8||newAppointment.begin>21);
    
    do{
        int remainingTime=22-newAppointment.begin;
        printf("\nGib eine Dauer ein (1-%d): ", remainingTime);
        scanf("%d", &newAppointment.duration);
        if(newAppointment.duration<1||newAppointment.duration>(22-newAppointment.begin)){
            printf("\nUngueltige Eingabe!");
            continue;
        }
    }while(newAppointment.duration<1||newAppointment.duration>(22-newAppointment.begin));
    
    return newAppointment;
}

void addAppointment(struct Appointment * schedule, int *length){
    if(*length==10){
        printf("\nDer Kalender ist voll!");
        return;
    }
    struct Appointment newAppointment=createAppointment();
    int position=*length;
    while(position>0&&newAppointment.begin<schedule[position-1].begin){
        schedule[position]=schedule[position-1];
        position--;
    }
    schedule[position]=newAppointment;
    (*length)++;
}

void deleteAppointment(struct Appointment * schedule, int *length){
    if(*length==0){
        printf("\nDer Kalender ist leer!");
        return;
    }
    printAppointments(schedule, *length);
    int index;
    printf("\nWelchen dieser Termine moechten Sie loeschen? (1-%d): ", *length);
    do{
        scanf("%d", &index);
        if(index<1||index>*length){
            printf("Ungueltige Eingabe!");
        }
        continue;
    }while(index<1||index>*length);
    
    for(int i=index-1; i<*length-1; ++i){
        schedule[i]=schedule[i+1];
    }
    (*length)--;
    printf("\nTermin %d wurde geloescht!", index);
}

int main(){
    struct Appointment schedule[10];
    int length=0;
    char choice;
    do{
        printf("\nNeuen Termin (n), Termin loeschen (d), Termine auflisten (l), Informationen ausgeben (i), Programm beenden (x)\nAuswahl: ");
        scanf(" %c", &choice);
        switch(choice){
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
                break;
            default:
                printf("\nUngueltige Eingabe!");
        }
    }while(choice!='x');
    return 0;
}