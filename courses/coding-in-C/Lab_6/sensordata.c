#include <stdio.h>

#define ARRAY_SIZE 3000

struct SensorData{
    float time;
    double probability;
};

struct Sensor{
    int id;
    double threshold;
    struct SensorData data[ARRAY_SIZE];
    int object_detection[ARRAY_SIZE];

};

int read_data(char filename[], struct Sensor *ptr_s){
    FILE *datei = fopen(filename, "r");
    if(datei == NULL){
        printf("read_data(): couldn't read file %s\n", filename);
        return 0;
    }
    float time = 0;
    float value = 0;
    int i = 0;
    while(fscanf(datei, "%f %f", &time, &value) == 2){
        struct SensorData set = {time, value};
        if(i < ARRAY_SIZE){
            ptr_s->data[i] = set;
            i++;
        }
        

    }

    if (ferror(datei)) {
        perror("Error reading file");
    }
    fclose(datei);
    return 1; 


}

void generate_signal(struct Sensor *ptr_s){
    for (int i = 0; i < ARRAY_SIZE; i++){
        if(ptr_s->data[i].probability >= ptr_s->threshold){
            ptr_s->object_detection[i] = 1;

        } else{
            ptr_s->object_detection[i] = 0;
        }
        
    }
}

int get_intervals(struct Sensor *ptr_s){
    int j = 0;
    printf("Sensor %i detections: ", ptr_s->id);
    for(int i = 1; i < ARRAY_SIZE; i++){
        if(ptr_s->object_detection[i] != ptr_s->object_detection[i-1]){
           if(j==0){
            printf("Start: %.2f s, ", ptr_s->data[i].time);
            j++;
           } else if(j==1){
            printf("End: %.2f s; ", ptr_s->data[i].time);
            j--;
           } else{
            printf("Error in get_intervals(): invalid time identifier");
            return 0;
           }
           
            
        }
    }
    printf("\n");
    return 1;
}

void compare_intervals(struct Sensor *ptr_s, struct Sensor *ptr_t){
    int j = 0;
    printf("Fused signal (both sensors): ");
    for(int i = 0; i <ARRAY_SIZE; i++){
        if(ptr_s->object_detection[i] == 1 && ptr_t->object_detection[i] == 1 && j == 0){
            printf("Start: %.2f s, ", ptr_s->data[i].time);
            j++;
        }
        if((ptr_s->object_detection[i] != 1 || ptr_t->object_detection[i] != 1) && j == 1){
            printf("End: %.2f s; ", ptr_s->data[i].time);
            j--;
        }


    }
    printf("\n");
}

int main(){
    struct Sensor sensor_1 ={1, 0.8};
    struct Sensor *ptr_1 = &sensor_1;
    if(read_data("sensor1.txt", ptr_1)){
        printf("Data read succesfully (Sensor 1)\n");

    } else{
        printf("main() coultdn't read sensor data from Sensor 1\n");
        return -1;
    }

    struct Sensor sensor_2 ={2, 0.7};
    struct Sensor *ptr_2 = &sensor_2;
    if(read_data("sensor2.txt", ptr_2)){
        printf("Data read succesfully (Sensor 2)\n");
        

    } else{
        printf("main() coultdn't read sensor data from Sensor 2\n");
        return -1;
    }

    generate_signal(ptr_1);
    generate_signal(ptr_2);

    if(!get_intervals(ptr_1)){
        printf("Failed to get Intervals (Sensor 1)\n");
        return -1;
    }
    if(!get_intervals(ptr_2)){
        printf("Failed to get Intervals (Sensor 2)\n");
        return -1;
    }
    compare_intervals(ptr_1, ptr_2);



    return 1;


}

