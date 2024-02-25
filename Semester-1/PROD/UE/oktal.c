#include <stdio.h>
#include <math.h>
int main() {
    int input,dec,zs;
    scanf("%d",&input);
    for(int i = 1; input != 0; i= i*8) {
        int digit = input%10;
        input = input/10;
        dec+=digit*i;
    }
    int dec_for_sum = dec;
    while(dec_for_sum!=0) {
        int digit = dec_for_sum%10;
        dec_for_sum = dec_for_sum/10;
        zs += digit;

    }
    printf(": dec.: %d\nZS: %d",dec,zs);
}
