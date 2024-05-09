#ifndef QUICK_SELECT_1_
#define QUICK_SELECT_1_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <chrono>
#include "InsertionSort.hpp"
const int & median3One( std::vector<int> & a, int left, int right );
void quickSelect(std::vector<int> &data, int left, int right, int k);
void quickSelect1 (const std::string & header, std::vector<int> data);


#endif 