#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <chrono>
void stdsort(const std::vector<int>& data, double percentile [3]);

int main (){
    std::ifstream file("test.txt");
    if (file.fail()) {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1); // exit if failed to open the file
    }
    std::string input;
    std::vector<int> data;
    while(file >> input){
        data.push_back(stoi(input));
    }
    double percentile[3] = {data.size() * .25 - 1, data.size() * .5 - 1, data.size() * .75 - 1};
    stdsort(data, percentile);
}

void stdsort(const std::vector<int>& data, double percentile [3] ){
    std::vector<int> sorted = data;
    const auto start = std::chrono::steady_clock::now(); //start of time
    std::sort(sorted.begin(), sorted.end());
    for(int i = 0; i < 3; i++){
        std::cout << sorted[percentile[i]] << " ";
    }
    std::cout << std::endl;
    const auto end = std::chrono::steady_clock::now(); //end time
    int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    std::cout << "Std Sort ran in "<<  time << " microseconds." << std::endl;
}