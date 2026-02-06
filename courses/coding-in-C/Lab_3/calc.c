#include <stdio.h>
#include <string.h>

float add(float a, float b);
float sub(float a, float b);
float mult(float a, float b);
float div(float a, float b);

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
    
    switch(operator){
        case '+':
        ergebnis = add(a,b);
        break;
        case '-': 
        ergebnis = sub(a,b);
        break;
        case '*':
        ergebnis = mult(a,b);
        break;
        case '/':
        if(b){
            ergebnis = div(a,b);
        } else{
            printf("\nDivide by 0 error!");
            return 1;
        }
        break;
        default:
        printf("\nUnknown operator!");
        return 1;
        break;
    

    }


    
        printf("\n Das Ergebnis aus ");
        printf("%.2f", a);
        printf("%c", operator);
        printf("%.2f", b);
        printf("=");
        printf("%.2f", ergebnis);
    
}

float add(float a, float b){
    return a+b;
}

float sub(float a, float b){
    return a-b;
}

float mult(float a, float b){
    return (a*b);
}

float div(float a , float b){
   return a/b;
}