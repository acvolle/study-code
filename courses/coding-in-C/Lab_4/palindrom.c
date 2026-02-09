#include <stdio.h>
#include <string.h>

int main(){
    char word[101];
    int palindrom = 1;

    printf("Geben Sie ein Wort ein (max. 100 Zeichen):");
    fgets(word, sizeof(word), stdin);

    char *ptr_anfang = word;
    char *ptr_ende = word;

    while(*ptr_ende != '\n'){
        ptr_ende++;
    }

    *ptr_ende = '\0'; //damit in der Ausgabe kein Zeilenumbruch ist
    ptr_ende--;
    char *ptr_back = ptr_ende;

    while(ptr_anfang != ptr_ende){
        if(*ptr_anfang != *ptr_back){
            palindrom = 0;

        }
        ptr_anfang++;
        ptr_back--;
    }

    if(palindrom){
        printf("Your provided word \"%s\" is a palindrome! :)", word);
    } else{
        printf("Your provided word \"%s\" is not a palindrome! :(", word);
    }



}