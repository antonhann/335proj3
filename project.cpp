#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <chrono>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
#include "InsertionSort.hpp"
int main (){
    std::vector<std::string> input = {"test_input1.txt", "test_input2.txt", "test_input3.txt"};
    for(int i = 0; i < 3; i++){
        std::ifstream file(input[i]);
        std::cout << input[i] << " is being ran!" << std::endl;
        if (file.fail()) {
            std::cerr << "File cannot be opened for reading." << std::endl;
            exit(1); // exit if failed to open the file
        }
        std::string header;        // new string variable
        getline(file, header); // read one line from the file
        std::string input;
        //std::vector<int> data = {5,6,7,3,8,9,1,2};
        std::vector<int> data = {};
        while(file >> input){
            data.push_back(stoi(input));
        }
        stdSort(header, data);
        quickSelect1(header, data);
        quickSelect2(header, data);
        countingSort(header,data);
        std::cout << std::endl;
    }
}

//g++ project.cpp StdSort.cpp QuickSelect1.cpp QuickSelect2.cpp CountingSort.cpp InsertionSort.cpp