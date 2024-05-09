#ifndef QUICK_SELECT_2_
#define QUICK_SELECT_2_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
#include <chrono>
#include "InsertionSort.hpp"
const int & median3Two( std::vector<int> & a, int left, int right );
void quickSelectRecursion(std::vector<int> &data, int left, int right, std::vector<int> keys);
void quickSelect2 (const std::string & header, std::vector<int> data);

#endif 