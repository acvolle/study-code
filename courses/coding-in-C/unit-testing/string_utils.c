#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>


int custom_len(char *string){
    if(string == NULL){
        return -1;
    }
    char *start = string;
    int count = 0;
    while(*start != '\0'){
        start++;
        count++;
    }
    return count;

}