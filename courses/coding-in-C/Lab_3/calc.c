#include <stdio.h>
#include <string.h>

int main(){
    float a = 0;
    float b = 0;
    char operator;
    float ergebnis;
    int fail = 0;

printf("Erste Zahl eingeben: ");
    if (scanf(" %f", &a) != 1) {
        printf("ungueltuge Eingabe!\n");
        return 1;
    }

    printf("Zweite Zahl eingeben: ");
    if (scanf(" %f", &b) != 1) {
        printf("Ungueltige Eingabe!\n");
        return 1;
    }

    printf("Welche Operation soll ausgeführt werden? +, -, *, /: ");
    if (scanf(" %c", &operator) != 1) {
        printf("Ungueltuge Eingabe\n");
        return 1;
    }
    

    if(operator == 0x2B){
        ergebnis = a+b;
    } else if(operator == 0x2D){
        ergebnis = a-b;
    } else if(operator == 0x2A){
        ergebnis = a*b;
    } else if(operator == 0x2F){
        if(b){
            ergebnis = a/b;
        } else{
            printf("\nDivide by 0 error!");
            fail = 1;
        }
    } else{
        printf("\nUnknown operator!");
        fail = 1;
    }
    if(!fail){
        printf("\n Das Ergebnis aus ");
        printf("%.2f", a);
        printf("%c", operator);
        printf("%.2f", b);
        printf("=");
        printf("%.2f", ergebnis);
    }
}