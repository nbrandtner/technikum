#include <stdio.h>
double einnahme(double input){
    double tax=0;
    if(input>200){
        tax=(input-200)*0.4;
        input=200;
    }
    if(input>50){
        tax+=(input-50)*0.2;
        input=50;
    }
    if(input>20){
        tax+=(input-20)*0.1;
        input=20;
    }
    printf("\nGezahlte Steuern: %.2lf Euro",tax);
    return tax;
}
int main(){
    // declare and initialize all needed variables
    double in=0, out=0, tax=0;
    double input=0;
    int cntin=0, cntout=0;
    double credit=100;
    char typ;
    double temptax=0;
    while (1) {
        printf("\nGuthaben: %.2lf Euro\nTyp:", credit);
        scanf(" %c", &typ);
        if (typ == '=') { //this breaks out of the while(1) loop to end the programm
            break;
        }
        printf("\nBetrag in Euro: ");
        scanf("%lf", &input);
        if (input < 0) {
            printf("\nDer Betrag kann nicht negativ sein.");
            continue; //this continues with the next while(1) loop, basically skipping over the current iteration
        }
        switch(typ){
            case 'e':
                temptax=einnahme(input); //function einnahme() returns the tax that has to be applied to the original amount
                tax+=temptax;
                in+=input-temptax;
                credit+=input-temptax;
                temptax=0;
                cntin++;
                break;

            case 's':
                in+=input;
                credit+=input;
                cntin++;
                break;

            case 'k':
                if(input>credit){
                    printf("\nDiese Kosten koennen nicht bezahlt werden.");
                    break;
                }else{
                    out+=input;
                    credit-=input;
                    cntout++;
                }
                break;

            default:
                break;
        }
    }
    double avgin,avgout;
    if(cntin==0){
        avgin=0;
    }else{
        avgin=in/cntin;
    }
    if(cntout==0){
        avgout=0;
    }else{
        avgout=out/cntout;
    }
    printf("\nRestguthaben: %.2lf Euro",credit);
    printf("\n%d Einnahmen mit durchschnittlichem Wert %.2lf Euro",cntin,avgin);
    printf("\n%d Ausgaben mit durchschnittlichem Wert %.2lf Euro",cntout,avgout);
    printf("\nGezahlte Steuern: %.2lf Euro",tax);
}
