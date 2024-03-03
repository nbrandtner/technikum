#include <stdio.h>
#define anz 10

double praemien(double betraege[], int anzahl, double grenze, double praemie){
    double summe=0;
    for(int i=0;i<anzahl;i++){
        if(betraege[i]>=grenze){
            summe+=praemie;
        }
    }
    return summe;
}

int eingabe(double betraege[], int max){
    int zaehler = 0;
    for (int i = 0; i < max; i++) {
        printf("Zahl %d: ", i+1);
        scanf("%lf", &betraege[i]);
        if (betraege[i] < 0) {
            return zaehler;
        }
        zaehler++;
    }
    return zaehler;
}

double sum(double betraege[], int anzahl){
    double summe=0;
    for (int i = 0; i < anzahl; i++){
        summe += betraege[i];
    }
    return summe;
}

int main() {
    double arr[anz] = {0};
    double grenze, praemie, gesamt;
    int n;

    n = eingabe(arr, anz);
    printf("Untergrenze: ");
    scanf("%lf", &grenze);
    printf("Praemie: ");
    scanf("%lf", &praemie);

    printf("Summe vor Praemien: %.2f\n", sum(arr, n));
    gesamt = praemien(arr, n, grenze, praemie);
    printf("Praemien gesamt: %.2f\n", gesamt);
    printf("Summe nach Praemien: %.2f\n", sum(arr, n)+gesamt);

    return 0;
}
