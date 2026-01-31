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
            // CHANGED: count hits of 0 correctly for R
            int t_hit = (100 - (current_pos % 100)) % 100;   // first click that hits 0 (mod 100)
            if (t_hit == 0) t_hit = 100;                     // clicks are 1..number
            if (number >= t_hit) counter += 1 + (number - t_hit) / 100;

            current_pos = (current_pos + number) % 100;

        }else if (direction == 'L'){
            // REMOVED: this was wrong and causes off-by when current_pos == 0
            // int negative_number = current_pos - number;
            // if (negative_number <= 0){
            //     counter += 1;
            // }
            // int rotations = abs(current_pos - number) / 100;
            // counter += rotations;

            // CHANGED: count hits of 0 correctly for L
            int t_hit = (current_pos % 100);                 // first click that hits 0 (mod 100)
            if (t_hit < 0) t_hit += 100;                     // safety
            if (t_hit == 0) t_hit = 100;                     // clicks are 1..number
            if (number >= t_hit) counter += 1 + (number - t_hit) / 100;

            current_pos = (current_pos - number) % 100;
            if (current_pos < 0){
                current_pos += 100;
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