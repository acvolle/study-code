#include <stdio.h>

int main(){

    char *letters = {"ABCDEFGH"};
    
    
    for(int i = 8; i>0; i--){
        for (int j = 0; j<8; j++){
            printf("%c", letters[j]);
            printf("%d", i);
            printf(" ");

        }
        printf("\n");
      
    }

    




}