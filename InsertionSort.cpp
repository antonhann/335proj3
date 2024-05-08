#include "InsertionSort.hpp"

void insertionSort (std::vector<int>& data){
    int j;
    for(int i = 1; i < data.size(); i++){
        j = i;
        while(j > 0 && data[j - 1] > data[j]){
            std::swap(data[j - 1], data[j]);
            j -= 1;
        }
    }
    return;
}
