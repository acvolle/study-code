#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    array[2] = 1;
    int *ptr_a = &array[2];
    array[4] = 1;
    int *ptr_b = &array[4];
    array[6] = 1;
    int *ptr_c = &array[6];

    int *ptr_first = &array[0];

    int temp_array[] = array;
    int *ptr_temp = temp_array;

    srand(time(0));

    for(int i = 0; i<8; i++){
        printf("At Time %i", i);
        for(int j = 0; j<10; j++){
            printf("%i", array[j]);
        }

        *ptr_a = 0;
        *ptr_b = 0;
        *ptr_c = 0;

        int **ptr_aa = &ptr_a;
        int **ptr_bb = &ptr_b;
        int **ptr_cc = &ptr_c;

        int *ptr_arr = array;

        move(ptr_aa, ptr_arr);
        move(ptr_bb, ptr_arr);
        move(ptr_cc, ptr_arr);

        int a_in = 1;
        int b_in = 1;
        int c_in = 1;

        if(*ptr_a == ptr_b){
            a_in = 0;
            b_in = 0;
        }
        if(*ptr_b == ptr_c){
            c_in = 0;
            b_in = 0;
        }
        if(*ptr_a == ptr_c){
            a_in = 0;
            c_in = 0;
        }
        




    }

}

void move(int **ptr, int *arr[]){
    if (*ptr == *arr[0]) {
        *ptr++;

    } else if ( *ptr == *arr[9]) {
        *ptr--;
        
    } else{
        int random_number = rand() % 2;
        if(random_number){
            *ptr++;
        } else{
            *ptr--;
        }

    }
}