#include <stdio.h>
#include <math.h>
int main() {
    int octalNumber,numDigits=0,dec,sum;
    int digit3,digit2,digit1;
    scanf("%o", &octalNumber);
    int temp = octalNumber;
    while (temp != 0) {
        temp /= 10;
        numDigits++;
    }
    switch(numDigits){
        case 3:
            digit3 = octalNumber % 8;
            octalNumber /= 8;
            digit2 = octalNumber % 8;
            octalNumber /= 8;
            digit1 = octalNumber % 8;
            
            dec=(digit3*pow(8, 2))+(digit2*8)+digit1;
            sum=digit3+digit2+digit1;
            break;
        case 2:
            digit2 = octalNumber % 8;
            octalNumber /= 8;
            digit1 = octalNumber % 8;
            
            dec=(digit2*(8))+digit1;
            sum=digit2+digit1;
            break;
        case 1:
            dec=octalNumber;
            sum=dec;
            break;
        default:
            printf("Something went wrong.. good luck");
    }
    printf(": dec.: %d\nZS: %d",dec,sum);
}
