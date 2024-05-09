#include "QuickSelect1.hpp"

const int & median3One( std::vector<int> & a, int left, int right )
{
    int center = ( left + right ) / 2;
    if( a[ center ] < a[ left ] )
        std::swap( a[ left ], a[ center ] );
    if( a[ right ] < a[ left ] )
        std::swap( a[ left ], a[ right ] );
    if( a[ right ] < a[ center ] )
        std::swap( a[ center ], a[ right ] );
    // Place pivot at position right - 1
    std::swap( a[ center ], a[ right - 1 ] );
    return a[ right - 1 ];
}

void quickSelect(std::vector<int> &data, int left, int right, int k){
    if(left + 20 <= right){
        const int pivot = median3One(data,left,right);
        int i = left;
        int j = right - 1;
        for(;;){
            while(data[++i] < pivot) {}
            while (pivot < data[--j]) {}
            if(i < j){
                std::swap(data[i],data[j]);
            }else{
                break;
            }
        }
        std::swap(data[i],data[right-1]);
        if(k <= i){
            quickSelect(data, left, i - 1, k);
        }else{
            quickSelect(data,i + 1, right, k);
        }
    }else{
        insertionSort(data,left, right);
    }
}

void quickSelect1 (const std::string & header, std::vector<int> data){
    const auto start = std::chrono::steady_clock::now(); //start of time
    quickSelect(data, 0, data.size() - 1, data.size() * .50); // Index of the 50th percentile 
    quickSelect(data, 0, data.size() * .50 - 2, data.size() * .25); // Index of the 25th percentile
    quickSelect(data, data.size() * .50 + 1, data.size() - 1, data.size() * .75); // Index of the 75th percentile
    int min = data[0];
    int max = data[0];
    for(int i = 0; i < data.size() * .25; i++){
        if(data[i] < min){
            min = data[i];
        }
    }
    for(int i = data.size() * .75 + 1; i < data.size(); i++){
        if(data[i] > max){
            max = data[i];
        }
    }
    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "P25: " << data[data.size() * .25 - 1] << std::endl;
    std::cout << "P50: " << data[data.size() * .50 - 1] << std::endl;
    std::cout << "P75: " << data[data.size() * .75 - 1] << std::endl;
    std::cout << "Max: " << max << std::endl;
    // const auto end = std::chrono::steady_clock::now(); //end time
    // int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    // std::cout << "Std Sort ran in "<<  time << " microseconds." << std::endl;
}

