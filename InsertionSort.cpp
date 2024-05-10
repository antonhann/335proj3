#include "InsertionSort.hpp"
/**
 * @brief insertion sort from left to right to be used 
 * when the quick select reaches a size of 20 or less.
 * 
 * @param: vector of int data, int left index, int right index
 */
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
