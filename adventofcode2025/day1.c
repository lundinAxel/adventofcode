#include <stdio.h>
#include <stdlib.h>

int day1(){

    int current_pos = 50;
    char direction;
    int number;
    int counter = 0;

    FILE *fptr = fopen("adventofcode_day1.txt", "r");
    char buffer[50];

    if (fptr == NULL){
        fprintf(stderr, "Error: could not open file\n");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), fptr)){
        direction = buffer[0];
        number = atoi(buffer + 1);

        if(direction == 'R'){
            current_pos = (current_pos + number) % 100;
            if(current_pos == 0){
                counter++;
            }

        }else if (direction == 'L'){

            current_pos = (current_pos - number) % 100;

            if(current_pos < 0){
            current_pos += 100;
            }
            if (current_pos == 0){
                counter++;
            }

        }else{
            fclose(fptr);
            return -2;
        }
    }
    fclose(fptr);
    return counter;
}

int main(){

    int result = day1();
    printf("Result: %d\n", result);

    return 0;
}