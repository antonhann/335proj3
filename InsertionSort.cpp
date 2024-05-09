#include "InsertionSort.hpp"

void insertionSort (std::vector<int>& data, int left, int right){
    int j;
    for(int i = left + 1; i <= right; i++){
        j = i;
        while(j > 0 && data[j - 1] > data[j]){
            std::swap(data[j - 1], data[j]);
            j -= 1;
        }
    }
    return;
}
