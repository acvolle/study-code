#include <stdio.h>

int main()
{
    FILE *datei = fopen("text.txt", "r");

    if (datei == NULL)
    {
        printf("Fehler beim erstellen der Datei");
        return -1;
    }

    int c = fgetc(datei);
    if (c != EOF)
    {
        printf("%c", c);
    }
    else
    {
        printf("Error!!!! Oh nein!! was ist denn da passiert?");
    }

    char str1[8];
    if (fgets(str1, 8, datei) != NULL)
    {
        printf("%s", str1);
    }
    else
    {
        printf("Error reading from file\n");
    }

    char str2[5];
    if (fscanf(datei, "%4s", str2) == 1)
    {
        printf("%s", str2);
    }
    else
    {
        printf("Error reading from file\n");
    }

    if (fclose(datei) != 0)
    {
        printf("Fehler beim schliessen der Datei");
        return -1;
    }

    return 1;
}