#include <iostream>
using namespace std; //using namespace verstößt gegen die coding convention

void printArray(int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[4] = {5, 2, 8, 1};
    int n = sizeof(arr)/sizeof(arr[0]); //besserer stil

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {  //früh
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArray(arr, n);
    }

    return 0;
}