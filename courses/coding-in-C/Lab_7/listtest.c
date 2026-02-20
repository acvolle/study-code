#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
    struct Node *next;
    double value;

}Node;

 Node *head = NULL;

Node *insert(double data){
      Node *res = malloc(sizeof(Node));
      res->next = NULL;
      res->value = data;
      return res;
}


int main(){

    Node *current = head;

    for (int i = 0; i<50; i++){
        if(head == NULL){
            head = insert(i+0.5);
            current = head;
        } else{
            current->next = insert(i+0.5);
            current = current->next;

        }


    }


    //Generate Array
    int array[51]; 
    srand(time(0));
    for(int i = 0; i<50; i++){
        array[i] = rand(); 
    }

    int a = rand();

    Node *ptr_new = malloc(sizeof(Node));
ptr_new->next = NULL;
ptr_new->value = a;
    Node *ptr_counter = head;
    for(int i = 0; i < 3; i++){
        ptr_counter = ptr_counter->next;
    }
    ptr_new->next = ptr_counter->next;
    ptr_counter->next = ptr_new;





    //free Memory
    current = head;
    while(current != NULL){
        Node *temp = current;
        printf("%f\n", temp->value);
        current = current->next;
        free(temp);
    }

}

