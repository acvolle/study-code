#include <stdio.h>

int main(){

    FILE *datei = fopen("text.txt", "w+");

    if(datei == NULL){
        printf("Fehler beim erstellen der Datei");
        return -1;
    }

    if(fputc('C', datei) == -1){
        printf("Fehler beim schreiben");
        return -1;
    }

    if(fputs("hristian Linder 123", datei) == EOF){
        printf("Fehler beim schreiben");
        return -1;
    }


    if(fprintf(datei, "%s", "ist bei der FDP") ==  EOF){
        printf("Fehler beim schreiben");
        return -1;
    }

    if(fclose(datei) != 0){
        printf("Fehler beim schliessen der Datei");
        return -1;
    }
    /*

    FILE *reader = fopen("text.txt", "r");

    if(reader == NULL){
        printf("Fehler beim erstellen der Datei");
        return -1;
    }

    if(fgetc(reader)!= EOF){
        printf("%c", fgetc(reader));
    } else{
        printf("Error!!!! Oh nein!! was ist denn da passiert?");
    }

    

    char str1[8];
    fgets(str1, 8, datei);
    printf(str1);


    char str2[5];
    fscanf(datei, "%s", str2);
    printf(str2);

    

    if(fclose(reader) != 0){
        printf("Fehler beim schliessen der Datei");
        return -1;
    }
    */





    return 1; 
}