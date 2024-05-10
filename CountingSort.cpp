#include "CountingSort.hpp"
/**
 * @brief using a frequency hashmap out of the dataset, create
 * a unique vector of the unique values in the dataset, iterate
 * through the unique values keeping track of the count, once we
 * hit the five number index we print it
 * 
 * @param: string of header, vector of ints of the dataset
 */
void countingSort (const std::string & header, std::vector<int> data){
    //const auto start = std::chrono::steady_clock::now(); //start of time
    std::unordered_map<int,int> hashmap;
    //make the frequency hashmap
    for(int i = 0; i < data.size(); i++){
        if(hashmap.find(data[i]) != hashmap.end()){
            hashmap[data[i]] += 1;
        }else{
            hashmap[data[i]] = 1;
        }
    }
    std::vector<int> keys = {1,static_cast<int>(data.size() * .25),static_cast<int>(data.size() * .50),static_cast<int>(data.size() * .75),static_cast<int>(data.size())};
    std::vector<int> unique;
    //fill in the unique vector
    for(const auto& pair: hashmap){
        unique.push_back(pair.first);
    }   
    std::sort(unique.begin(), unique.end());
    int k = 0; //key index
    int count = 0;
    std::cout << header << std::endl;
    //iterate thru the unique vector and keep track of the count of elements,
    //if we pass a current key we will print it
    for(int i = 0; i < unique.size(); i++){
        count += hashmap[unique[i]];
        while(count >= keys[k]){
            if(k == 0){
                std::cout << "Min: " << unique[i] << std::endl;
            }
            else if(k == 1){
                std::cout << "P25: " << unique[i] << std::endl;
            }
            else if(k == 2){
                std::cout << "P50: " << unique[i] << std::endl;
            }
            else if(k == 3){
                std::cout << "P75: " << unique[i] << std::endl;
            }
            else if(k == 4){
                std::cout << "Max: " << unique[i] << std::endl;
            }
            k += 1;
        }
    }
    std::cout << "Unique: " << unique.size() << std::endl;
    // const auto end = std::chrono::steady_clock::now(); //end time
    // int time = std::chrono::duration <double, std::micro> (end - start).count(); //time to complete instructions
    // std::cout << "Counting Sort: "<<  time << " microseconds." << std::endl;
}