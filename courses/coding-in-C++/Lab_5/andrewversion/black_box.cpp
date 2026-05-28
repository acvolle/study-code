#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
T get_data_sum(const std::vector<T>& data){
    return std::accumulate(data.begin(), data.end(), T());
}

template<>
bool get_data_sum(const std::vector<bool>& data){
    int true_count = 0;
    int false_count = 0;
    for(bool elem : data){
        if(elem == true){
            true_count++;
        } else{
            false_count++;
        }
    }
    if(true_count > false_count){
        return true;
    } else{
        return false;
    }
}

template <typename T>
T get_lowest_value(const std::vector<T>& data){
    return *std::min_element(data.begin(), data.end());
}

template <typename T>
T get_highest_value(const std::vector<T>& data){
    return *std::max_element(data.begin(), data.end());
}

template <typename T>
void print_report(const std::vector<T>& data){
    std::cout << "Report: " << std::endl << "[";
    for(T elem : data){
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Sum of values: " << get_data_sum(data) << std::endl;
    std::cout << "Minimum value: " << get_lowest_value(data) << std::endl;
    std::cout << "Maximum value: " << get_highest_value(data) << std::endl;
    std::cout << std::endl;
}

template<>
void print_report(const std::vector<bool>& data){
    std::cout << "Report: " << std::endl << "[";
    for(bool elem : data){
        std::cout << elem << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << "Overall average: " << std::boolalpha << get_data_sum(data) << std::endl;
    std::cout << std::endl;

}


template <typename T, size_t U>
std::vector<T> convert_to_vec(const T (&frames)[U]){
    int array_size = static_cast<int>(U);
    std::vector<T> temp;
    for(int i = 0; i < array_size; i++){
        temp.push_back(frames[i]);
    }

    return temp;
}

int main(){


    int array[6] = {5, 7, 88, 10, 2, 7};
    std::vector<int> vec = convert_to_vec(array);
    print_report(vec);

    bool barr[5] = {true, false, false, true, false};
    std::vector<bool> bvec = convert_to_vec(barr);
    print_report(bvec);

}