#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char input[41];
    scanf("%s",input);
    char inputcpy[41];
    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }
    for(int i=0, j; i < sizeof(input); i++){
        while(!(input[i]>='a'&&input[i]<='z')){
            for (j = i; input[j] != '\0'; ++j) {
                // if jth element of input is not an alphabet,
                // assign the value of (j+1)th element to the jth element
                input[j] = input[j + 1];
            }
            input[j] = '\0';
        }
    }
    strcpy(inputcpy,input);
    strrev(input);
    if(strcmp(inputcpy,input)==0){
        printf(": true");
    }else{
        printf(": false");
    }
    return 0;
}