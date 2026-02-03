#include <stdio.h>

char *letters = {"ABCDEFGH"};

void printLetters();
void printRows(int k);

int main(){
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

void printRows(int k){
    
}

void printDividers(){

}