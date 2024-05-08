#include "StdSort.hpp" 

void stdSort (const std::string & header, std::vector<int> data){
    std::vector<int> sorted = data;
    const auto start = std::chrono::steady_clock::now(); //start of time
    std::sort(sorted.begin(), sorted.end());
    std::cout << header << std::endl;
    std::cout << "Min: " << sorted[0] << std::endl;
    std::cout << "P25: " << sorted[data.size() * .25 - 1] << std::endl;
    std::cout << "P50: " << sorted[data.size() * .50 - 1] << std::endl;
    std::cout << "P75: " << sorted[data.size() * .75 - 1] << std::endl;
    std::cout << "Max: " << sorted[data.size() - 1];

    std::cout << std::endl;
    // const auto end = std::chrono::steady_clock::now(); //end time
    // int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    // std::cout << "Std Sort ran in "<<  time << " microseconds." << std::endl;
}