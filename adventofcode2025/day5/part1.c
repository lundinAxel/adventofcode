#include <stdio.h>
#include <stdlib.h>



typedef struct {
    long long start;
    long long end;

}Range;

Range freshRange[1000000];

long long cafeteria(){
    long long sum = 0;
    long long availableIds;
    int count = 0;
    FILE *fptr;

    fptr = fopen("cafeteria.txt", "r");

    if (fptr == NULL){
        printf("File not opened\n");
        exit(1);
    }

    while(fscanf(fptr, "%lld-%lld", &freshRange[count].start, &freshRange[count].end) == 2){
        count++;
    }

    fscanf(fptr, " ");

    while (fscanf(fptr, "%lld", &availableIds) == 1){
        for (long long i = 0; i < count; i++){
            if(availableIds >= freshRange[i].start && availableIds <= freshRange[i].end){
                sum++;
                break;
            }
        }
    }
    return sum;    
}

int main(){
    long long result = cafeteria(); //It's +1 in sum due to fscanf, use fgets
    printf("# of Fresh IDs: %lld\n", result); 
    return 0;
}
