#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** scanWords() {
    char** words= (char**)calloc(1, sizeof(char*)), **tmp;
    int i=0;
    while(1) {
        char buf[81];
        scanf("%80s", buf);
        if(buf[0]=='-') break;
        if(NULL==(tmp = (char**)realloc(words, sizeof(char*)*(i+2)))) {
            printf("out of memory");
            break;
        }
        words=tmp;
        words[i] = (char*)calloc(strlen(buf)+1, sizeof(char));
        strcpy(words[i], buf);
        i++;
    }
    words[i] = NULL;
    return words;
}

int countWord(char *text, char* word) {
    int count = 0;
    char *tmp = text;
    while((tmp = strstr(tmp, word)) != NULL) {
        count++;
        tmp++;
    }
    return count;
}

void freeAll(char** words) {
    int i = 0;
    while(words[i] != NULL) {
        free(words[i]);
        i++;
    }
    free(words);
}

int main() {
    char text[1001];
    fgets(text, 1001, stdin);

    char** words = scanWords();
    printf("text: words:\n");
    for(int i = 0; words[i] != NULL; i++) {
        printf("%s: %d\n", words[i], countWord(text, words[i]));
    }


    freeAll(words);

    return 0;
}