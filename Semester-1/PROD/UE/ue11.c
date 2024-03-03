#include <stdio.h>
#include <stdlib.h>

int encode(int h, int m){
    int zeit;
    zeit=(h*100)+m;
    return zeit;
}

int read(){
    int stunden;
    int minuten;
    scanf("%d %d",&stunden,&minuten);
    int neuZeit= encode(stunden,minuten);
    printf("hours: minutes: ");
    return neuZeit;
}

int hours(int t){
    int stunden=t/100;
    return stunden;
}

int minutes(int t){
    int minuten=t%100;
    return minuten;
}

void print(int t){
    printf("%02d:%02d",hours(t),minutes(t));
}

int add(int t1, int t2){
    int minuten=minutes(t1)+minutes(t2);
    int stunden=hours(t1)+hours(t2);
    if(minuten>59){
        minuten=minuten-60;
        stunden=stunden+1;
    }
    if(stunden>23){
        stunden=stunden-24;
    }
    return encode(stunden,minuten);
}

int total_minutes(int t){
    int minuten=minutes(t);
    int stunden=hours(t);
    minuten=minuten+stunden*60;
    return minuten;
}

#include "use_this_main.c"
