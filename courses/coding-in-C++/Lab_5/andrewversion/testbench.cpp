#include <iostream>
//guaranteed for int, double, string
template <typename T>
void swap_values(T& val_1, T& val_2){
    T temp_val = val_1;
    val_1 = val_2;
    val_2 = temp_val;
}
/*since a swap_values function for int,double and string have the same functionality,
we can make the code both shorter (one function istead of three almost identical ones) and 
easier to use (you can use the same function wothout worries, no needing to check which fucntion
you have to use to swap for each data type) by using a template*/ 

//guaranteed for int, double, char
template <typename T, size_t U>
void print_sensor_frames(const T (&frames)[U]){
    int array_size = static_cast<int>(U);
    std::cout << "[";
    for(int i = 0; i < array_size-1; i++){
        std::cout << frames[i] << ", ";
    }
    std::cout << frames[array_size-1] << "]" << std::endl;
}

//size of array is not needed as it is recieved from the static array size. 
//Any errors in determining the size and passing it are solved.


//guaranteed for int, double
template <typename T, size_t U>
T get_smallest_value(const T (&frames)[U]){
    int array_size = static_cast<int>(U);
    T current_lowest = frames[0];
    for(int i = 0; i < array_size; i++){
        if(frames[i] < current_lowest){
            current_lowest = frames[i];
        }
    }

    return current_lowest;
}



template <typename T, typename U>
void print_value_pair(const std::string& label1, const T& value1, const std::string& label2, const U& value2){
    std::cout << label1 << ": " << value1;
    std::cout << " | ";
    std::cout << label2 << ": " << value2 << std::endl;
}

int main(){
    std::string a = "Hallo";
    std::string b = "Amrcel Davis";
    swap_values(a, b);
    std::cout << "A:" << a << " B:" << b << std::endl;
    
    double arr3[4] = {0.1, 0.4, 5.5, 0.002};
    int arr1[5] = {11, 22, 3, 4, 5};
    print_sensor_frames(arr1);
    char arr2[] = {'C', 'B', 'A'};
    print_sensor_frames(arr2);

    std::cout << get_smallest_value(arr3) << std::endl;

    print_value_pair("Channel", "motor_temp", "Priority", 2);
    print_value_pair("Double", 0.67, "Priority", 2);

}