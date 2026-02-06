#include <stdio.h>
#include <string.h>

void change(char satz[]);

int main(){
    char phrase[] = "Curly bird catches the worm";
    char (*ptr_phrase)[] = &phrase; //pointer to whole array
    char *ptr_p1 = phrase; // pointer to fist element of array
     
    // prints out both full prheses
    printf(phrase);
    printf("\n%s",*ptr_phrase);
    printf("\n%c", *ptr_p1);

    *ptr_p1 = 'E';
    ptr_p1++;
    *ptr_p1 = 'a';

    printf("\n%s",*ptr_phrase);

    char c[] = "AAtions speak louder than words";
    char* ptr_p3 = c;

    change(c);


}

void change(char satz[]){
    char *ptr_p2 = satz;
    ptr_p2++;
    printf("%c", *ptr_p2);
    *ptr_p2 = 'c';

    printf("\n%s",satz);

}

