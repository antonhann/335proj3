#include "QuickSelect2.hpp"
/**
 * @brief swaps the median to the pivot spot
 * 
 * @param: vector of ints of the dataset, int left index, int right index
 */
const int & median3Two( std::vector<int> & a, int left, int right )
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
 * @brief quickselect but with a vector of keys and we recursively call on the
 * pivots upper and lower half, updating the keys for the correct recursive call and side
 * 
 * @param: vector of ints of the dataset, int left index, int right index,
 * vector of ints of the keys
 */
void quickSelectRecursion(std::vector<int> &data, int left, int right, std::vector<int> keys){
    //base case of recursion
    if(keys.size() == 0){
        return;
    }
    //if size > 20
    if(left + 20 <= right){
        const int pivot = median3Two(data,left,right);
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
        std::vector<int> keysLeft;
        std::vector<int> keysRight;
        for(int k = 0; k < keys.size(); k++){
            //update left key vector call
            if(keys[k] < i){
                keysLeft.push_back(keys[k]);
            }
            //update right key vector call
            if(keys[k] > i){
                keysRight.push_back(keys[k]);
            }
        }
        //call left side pivot
        quickSelectRecursion(data, left, i - 1, keysLeft);
        //call right side pivot
        quickSelectRecursion(data,i + 1, right, keysRight);
    }else{
        insertionSort(data,left, right);
    }
}
/**
 * @brief call quick select recursively with the keys being the five number summary,
 * and then print the five numbers
 * 
 * @param: string of header, vector of ints of the dataset
 */
void quickSelect2 (const std::string & header, std::vector<int> data){
    //const auto start = std::chrono::steady_clock::now(); //start of time
    std::vector<int> keys = {1,static_cast<int>(data.size() * .25),static_cast<int>(data.size() * .50),static_cast<int>(data.size() * .75),static_cast<int>(data.size())};
    quickSelectRecursion(data, 0, data.size() - 1, keys); // Index of the 50th percentile 
    quickSelectRecursion(data, 0, data.size() * .50 - 2, keys); // Index of the 25th percentile
    quickSelectRecursion(data, data.size() * .50 + 1, data.size() - 1, keys); // Index of the 75th percentile
    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << data[data.size() * .25 - 1] << std::endl;
    std::cout << "P50: " << data[data.size() * .50 - 1] << std::endl;
    std::cout << "P75: " << data[data.size() * .75 - 1] << std::endl;
    std::cout << "Max: " << data[data.size() - 1] << std::endl;
    // const auto end = std::chrono::steady_clock::now(); //end time
    // int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    // std::cout << "QuickSelect Two: "<<  time << " microseconds." << std::endl;
}