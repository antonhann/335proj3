#include "QuickSelect1.hpp"
/**
 * @brief swaps the median to the pivot spot
 * 
 * @param: vector of ints of the dataset, int left index, int right index
 */
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
/**
 * @brief quick select algorithm but when the left and right index reaches <= 20,
 * we do insertion sort on the corresponding portion of the data
 * 
 * @param: vector of ints of the dataset, int left index, int right index, int key index
 */
void quickSelect(std::vector<int> &data, int left, int right, int k){
    //if size > 20
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
/**
 * @brief calls quick select three times on the 25,50,75 percentile
 * and then get the min and max
 * 
 * @param: string of header, vector of ints of the dataset
 */
void quickSelect1  (const std::string & header, std::vector<int> data){
    //const auto start = std::chrono::steady_clock::now(); //start of time
    quickSelect(data, 0, data.size() - 1, data.size() * .50); // 50th percentile 
    quickSelect(data, 0, data.size() * .50 - 2, data.size() * .25); //25th percentile
    quickSelect(data, data.size() * .50 + 1, data.size() - 1, data.size() * .75); //75th percentile
    int min = data[0];
    int max = data[0];
    //get the min
    for(int i = 0; i < data.size() * .25; i++){
        if(data[i] < min){
            min = data[i];
        }
    }
    //get max
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
    // std::cout << "QuickSelect One: "<<  time << " microseconds." << std::endl;
}

