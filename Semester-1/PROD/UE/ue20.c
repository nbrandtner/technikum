#include <stdio.h>
#include <stdlib.h>

int* sortArr(int* arr, int length){
    int i, j, temp;
    for (i = 0; i < length; i++) {     
        for (j = 0; j < length-i-1; j++) { 
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

struct diff{
    int index1;
    int index2;
    int diff;
};

void findSmallestDifference(int* arr1, int* arr2, int length1, int length2){
    int diff=0;
    int idx1=0,idx2=0;
    struct diff smallestDiff={0,0,2147483646};

    
    while(1){
        diff=abs(arr1[idx1]-arr2[idx2]);
        if (diff<smallestDiff.diff){
            smallestDiff.diff=diff;
            smallestDiff.index1=idx1;
            smallestDiff.index2=idx2;
        }
        if(arr1[idx1]<arr2[idx2]){
            idx1++;
        }else{
            idx2++;
        }
        if(idx1==length1||idx2==length2){
            printf(": %d (%d, %d)",smallestDiff.diff,arr1[smallestDiff.index1],arr2[smallestDiff.index2]);
            break;
        }
    }
}

int main(){
    int length1=0;
    int length2=0;

    scanf("%d",&length1);
    scanf("%d",&length2);

    int *arr1 = malloc(sizeof(int)*length1);
    int *arr2 = malloc(sizeof(int)*length2);

    for(int i=0;i<length1;++i){
        scanf("%d",&arr1[i]);
    }
    for(int i=0;i<length2;++i){
        scanf("%d",&arr2[i]);
    }
    
    sortArr(arr1,length1);
    sortArr(arr2,length2);

    findSmallestDifference(arr1,arr2,length1,length2);

    free(arr1);
    free(arr2);

    return 0;
}