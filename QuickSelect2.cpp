#include "QuickSelect2.hpp"
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

void quickSelectRecursion(std::vector<int> &data, int left, int right, std::vector<int> keys){
    if(keys.size() == 0){
        return;
    }
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
            if(keys[k] < i){
                keysLeft.push_back(keys[k]);
            }
            if(keys[k] > i){
                keysRight.push_back(keys[k]);
            }
        }
        quickSelectRecursion(data, left, i - 1, keysLeft);
        quickSelectRecursion(data,i + 1, right, keysRight);
    }else{
        InsertionSort(data,left, right);
    }
}
void quickSelect2 (const std::string & header, std::vector<int> data){
    const auto start = std::chrono::steady_clock::now(); //start of time
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
    // std::cout << "Std Sort ran in "<<  time << " microseconds." << std::endl;
}