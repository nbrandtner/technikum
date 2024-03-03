#include <stdio.h>

double guthaben = 100.00;
double betrag = 0;
double steuern = 0.00;
double t1 = 0.00;  // Teilbetr�ge f�r Steuerrechnung
double t2 = 0.00;
double t3 = 0.00;
double t4 = 0.00;
int ausgabe = 0;
int einnahme = 0;
double durchschnitteinnahme = 0.00;
double durchschnittausgabe = 0.00;
double steuerngesamt = 0.00;
double einnahmegesamt = 0.00;
double ausgabegesamt = 0.00;
char input;

int main()
{

    printf("\nGuthaben: %.2f Euro\n", guthaben);

    while(1)
    {
        printf("Typ: ");
        scanf(" %c", &input);

        while(input == 's')  //steuerfreie Einnahmen
        {
            while(1)        //while-Schleife falls Betrag negativ, dann Betrag erneut eingeben
            {
                printf("\nBetrag in Euro: ");
                scanf(" %lf", &betrag);

                if(betrag < 0)
                {
                    printf("\nDer Betrag kann nicht negativ sein.");
                    printf("\nGuthaben: %.2f Euro\n", guthaben);
                    break;
                }
                else
                {
                    guthaben = guthaben + betrag;
                    printf("\nGuthaben: %.2f Euro\n", guthaben);
                    einnahme = einnahme + 1;                        //z�hlt Einnahmen mit
                    einnahmegesamt = einnahmegesamt + betrag;       //gesamte Einnahme wird f�r Durchschnittsberechnung dazugez�hlt
                    break;
                }

            }
            break;
        }

        while(input == 'e')  //besteuerte Einnahmen
        {
            while(1)
            {
            printf("\nBetrag in Euro: ");
            scanf("%lf", &betrag);

            t1 = betrag * 0;                    //Teilbetrag 1
            t2 = (betrag - 20) * 0.1;           //Teilbetrag 2
            t3 = (betrag - 50) * 0.2 + 3;       //Teilbetrag 3
            t4 = (betrag - 200) * 0.4+ 33;      //Teilbetrag 4


            if(betrag < 0)
            {
                printf("\nDer Betrag kann nicht negativ sein.");
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                break;
            }
            einnahme = einnahme + 1;            //z�hlt Einnahmen mit
            if(betrag <= 20)
            {
                guthaben = guthaben + betrag - t1;
                steuern = t1;
                printf("\nGezahlte Steuern: %.2f Euro", steuern);
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                steuerngesamt = steuerngesamt + steuern;                //Steuern werden zusammengez�hlt
                einnahmegesamt = einnahmegesamt + betrag - steuern;     //Einnahmen werden exklusive Steuern zusammengez�hlt
                break;
            }
            if(betrag > 20 && betrag <= 50)
            {
                guthaben = guthaben + betrag - t2;
                steuern = t2;
                printf("\nGezahlte Steuern: %.2f Euro", steuern);
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                steuerngesamt = steuerngesamt + steuern;                //Steuern werden zusammengez�hlt
                einnahmegesamt = einnahmegesamt + betrag - steuern;     //Einnahmen werden exklusive Steuern zusammengez�hlt
                break;
            }
            if(betrag > 50 && betrag <= 200)
            {
                guthaben = guthaben + betrag - t3;
                steuern = t3;
                printf("\nGezahlte Steuern: %.2f Euro", steuern);
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                steuerngesamt = steuerngesamt + steuern;                //Steuern werden zusammengez�hlt
                einnahmegesamt = einnahmegesamt + betrag - steuern;     //Einnahmen werden exklusive Steuern zusammengez�hlt
                break;
            }
            if(betrag > 200)
            {
                guthaben = guthaben + betrag - t4;
                steuern = t4;
                printf("\nGezahlte Steuern: %.2f Euro", steuern);
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                steuerngesamt = steuerngesamt + steuern;                //Steuern werden zusammengez�hlt
                einnahmegesamt = einnahmegesamt + betrag - steuern;     //Einnahmen werden exklusive Steuern zusammengez�hlt
                break;
            }
            }
            break;
        }

        while(input == 'k')
        {
            while(1)
            {
            printf("\nBetrag in Euro: ");
            scanf("%lf", &betrag);

            if(betrag < 0)
            {
                printf("\nDer Betrag kann nicht negativ sein.");
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                break;                               //springt mit continue an Anfang der Schleife
            }

            if(betrag > guthaben)                       //Wenn eingegebener Betrag gr��er als das aktuelle Guthaben ist wird geprintet
            {
                printf("\nDiese Kosten koennen nicht bezahlt werden.");
                printf("\nGuthaben: %.2f Euro\n", guthaben);
                break;                               //springt mit continue an Anfang der Schleife
            }
            guthaben = guthaben - betrag;
            printf("\nGuthaben: %.2f Euro\n", guthaben);
            ausgabe = ausgabe + 1;                      //z�hlt Ausgaben mit
            ausgabegesamt = ausgabegesamt + betrag;     //gesamte Ausgabe wird mitgez�hlt f�r Durchschnittsberechnung
            break;
            }
            break;
        }

        while(input == '=')
        {
            durchschnitteinnahme = einnahmegesamt / einnahme;       //gesamte Einnahmen durch wie viele Einnahmen gemacht wurden

            if(einnahme == 0)
                durchschnitteinnahme = 0;

            durchschnittausgabe = ausgabegesamt / ausgabe;          //gesamte Ausgaben durch wie viele Ausgaben gemacht wurden

            if(ausgabe == 0)
                durchschnittausgabe = 0;


            printf("\nRestguthaben: %.2f Euro", guthaben);
            printf("\n%d Einnahmen mit durchschnittlichem Wert %.2f Euro", einnahme, durchschnitteinnahme);
            printf("\n%d Ausgaben mit durchschnittlichem Wert %.2f Euro", ausgabe, durchschnittausgabe);
            printf("\nGezahlte Steuern: %.2f Euro\n", steuerngesamt);
            break;
        }
        if(input == '=')
            break;
    }

    return 0;
}
