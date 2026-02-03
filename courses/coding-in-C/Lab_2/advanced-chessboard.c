#include <stdio.h>

char *letters = {"ABCDEFGH"};

void printLetters();
void printRow(int k);
void printDividers();

int main(){
    printLetters();

    for(int i = 8; i > 0; i--){
        printDividers();
        printRow(i);
    }

    printLetters();

}


void printLetters(){
    printf(" ");
    for(int i = 0; i < 8; i++){
        printf("   ");
        printf("%c", letters[i]);
    }
    printf("\n");
}

void printRow(int k){
    printf("%d", k);
    printf(" ");

    for(int i = 0; i<4; i++){
        if(!(k%2)){
            printf("|###");
            printf("|   ");

        } else{
            printf("|   ");
            printf("|###");
        }

    }
    printf("| ");
    printf("%d", k);
    printf("\n");
}

void printDividers(){
    printf("  ");
    for(int i = 0; i <8; i++){
        printf("+---");
    }
    printf("+");
    printf("\n");

}