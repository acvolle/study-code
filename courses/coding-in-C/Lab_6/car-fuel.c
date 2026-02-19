#include <stdio.h>

struct car{
    float fuel_level;
    float max_fuel_level;
    char model[30];
};

int refuel(struct car *p, float fuel){
    float new_level = p->fuel_level + fuel;

    if(new_level <= p->max_fuel_level){
        p->fuel_level = new_level;
        return 1;
    } else{
        return 0;
    }

}

int main(){

    struct car car1 = {1, 50, "Fiat 500"};
    float additional = 0;
    struct car *ptr_car = &car1;
    printf("How much fuel would you like to add?");
    scanf("%f", &additional);


    if(refuel(ptr_car, additional)){
        printf("Success! You have refueled %2f liters", additional);
    } else{
        printf("Error! Not enouch space in fuel tank! Max. is %2f liters", ptr_car->max_fuel_level);
    }

    return 1;

}