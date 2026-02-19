#include <stdio.h>

int main(){
    FILE *datei = fopen("text.txt", "r");

    if(datei == NULL){
        printf("Fehler beim erstellen der Datei");
        return -1;
    }

    if(fgetc(datei)!= EOF){
        printf("%c", fgetc(datei));
    } else{
        printf("Error!!!! Oh nein!! was ist denn da passiert?");
    }

    

    char str1[8];
    fgets(str1, 8, datei);
    printf(str1);


    char str2[5];
    fscanf(datei, "%s", str2);
    printf(str2);

    if(fclose(datei) != 0){
        printf("Fehler beim schliessen der Datei");
        return -1;
    }
    

    return 1;
    
}