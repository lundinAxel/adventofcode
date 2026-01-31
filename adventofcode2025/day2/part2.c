#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long giftShop(){
    long long sumId = 0, startId, lastId;
    FILE* fptr;
    char strId[30], strFirstHalf[20], strSecondHalf[20];


    fptr = fopen("input.txt", "r");

    if (fptr == NULL) {
        printf("File not opened\n");
        return 0;
    }

    while (fscanf(fptr, "%lld-%lld,", &startId, &lastId) == 2) {
        printf("Processing range: %lld to %lld\n", startId, lastId);
        
        for (long long i = startId; i <= lastId; i++){
            int count = 0;

            sprintf(strId, "%lld", i);
            //printf("integer i: %d to string: %s\n", i, strId);
            
            int half = strlen(strId) / 2;
            for (int j = 0; j < half; j++){
                strFirstHalf[j] = strId[j];
            }
            strFirstHalf[half] = '\0';

            for (int k = half; k < strlen(strId); k++){
                strSecondHalf[count] = strId[k];
                count++;
            }
            strSecondHalf[count] = '\0';

            if (strcmp(strFirstHalf, strSecondHalf) == 0){
                //printf("its the same\n");
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