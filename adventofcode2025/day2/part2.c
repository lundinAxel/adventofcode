#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long giftShop(){
    long long sumId = 0, startId, lastId;
    FILE* fptr;
    char strId[30], strFirstHalf[20], strSecondHalf[20], 
    strPattern[20], strPatternCmp[20];



    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("File not opened\n");
        return 0;
    }

    while (fscanf(fptr, "%lld-%lld,", &startId, &lastId) == 2) {
        printf("Processing range: %lld to %lld\n", startId, lastId);
        
        for (long long i = startId; i <= lastId; i++){
            int count = 0;
            int isInvalid = 0;
            
            sprintf(strId, "%lld", i);
            int len = strlen(strId);
            int half = strlen(strId) / 2;

            for (int P = 1; P <= (half); P++){
                if ((len % P) == 0){
                    int allMatch = 1;
                    for (int l = 0; l < len - P; l++){
                        if (strId[l] != strId[l + P]) {
                            allMatch = 0;
                            break;
                        }
                    }
                    if (allMatch) {
                        isInvalid = 1;
                        break;
                    }
                }
            }

            if (isInvalid) {
                sumId += i;
            }
        }
    }

    return sumId;
}

int main(){
    long long test = giftShop();
    printf("Result: %lld\n", test);
}