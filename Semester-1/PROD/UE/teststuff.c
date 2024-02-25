#include <stdio.h>
#include <stdlib.h>

/* put your code here */

/* CodeRunner has its own copy of use_this_main.c, 
   no need to integrate its contents into the answer */
#include "use_this_main.c"

int encode(int h, int m){
    //kodiert eine Uhrzeit mit h Stunden und m Minuten im oben angegebenen Format.
    int time;
    time=h*100+m;
    return time;
}

int read(){
    //liest eine Uhrzeit an der Konsole.
    //Die Funktion frägt an der Konsole nach Stunden und Minuten, liest diese ein und gibt eine codierte Uhrzeit mit den eingelesenen Werten zurück.
    int h,m;
    scanf("%d %d",&h,&m);
    int encodedTime= encode(h,m);
    return encodedTime;
}

int hours(int t){
    //extrahiert die Stunden aus t.
    return t/100;
}

int minutes(int t){
    //extrahiert die Minuten aus t.
    return t%100;
}

void print(int t){
    //gibt die Uhrzeit t im Format HHMM aus (zwei Stellen, führende Null, ohne Zeilenschaltung am Ende).
    printf("%02d:%02d",hours(t),minutes(t));
}

int add(int t1, int t2){
    //addiert t2 zu t1.
    
}

int total_minutes(int t){
    //rechnet eine Uhrzeit in Minuten (seit Mitternacht) um.
    
}