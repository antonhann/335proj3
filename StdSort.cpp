#include "StdSort.hpp" 

void stdSort (const std::string & header, std::vector<int> data){
    const auto start = std::chrono::steady_clock::now(); //start of time
    std::sort(data.begin(), data.end());
    // const auto end = std::chrono::steady_clock::now(); //end time
    // int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    // std::cout << "Std Sort ran in "<<  time << " microseconds." << std::endl;
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