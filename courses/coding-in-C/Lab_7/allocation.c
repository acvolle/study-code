#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Enter an Integer:\n");

    int *ptr_n = malloc(sizeof *ptr_n);

    /* Malloc: Dient der Initialiserung EINES Objektes, erstellter Speicher wird NICHT initialisiert*/

    scanf("%i", ptr_n);

    int *ptr_array = calloc(*ptr_n, sizeof *ptr_array);
    /*Calloc: Dient der Initialisierung von Arrays/mehreren Objekten, ertellter Speicher wird Null-initialisiert*/

    for(int i = 0; i < *ptr_n; i++){
        *(ptr_array+i) = i*i;
    }

    void *ptr_temp = realloc(ptr_array, sizeof(*ptr_array)*(*ptr_n)*2);

    if(ptr_temp != NULL){
        ptr_array = ptr_temp;
    } else{
        return -1;
    }
    
    for(int i = *ptr_n; i < *ptr_n*2; i++){
        *(ptr_array+i) = i*i;
    }

    for(int i = 0; i < *ptr_n*2; i++){
        printf("%i\n", ptr_array[i]); 
    }

    free(ptr_n);
    free(ptr_array);


}