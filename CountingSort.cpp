#include "CountingSort.hpp"

void CountingSort (const std::string & header, std::vector<int> data){
    const auto start = std::chrono::steady_clock::now(); //start of time
    std::unordered_map<int,int> hashmap;
    for(int i = 0; i < data.size(); i++){
        if(hashmap.find(data[i]) != hashmap.end()){
            hashmap[data[i]] += 1;
        }else{
            hashmap[data[i]] = 1;
        }
    }
    std::vector<int> keys = {1,static_cast<int>(data.size() * .25),static_cast<int>(data.size() * .50),static_cast<int>(data.size() * .75),static_cast<int>(data.size())};
    std::vector<int> unique;
    for(const auto& pair: hashmap){
        unique.push_back(pair.first);
    }   
    std::sort(unique.begin(), unique.end());
    //std::cout << unique.size() << std::endl;
    int k = 0;
    int count = 0;
    std::cout << header << std::endl;
    for(int i = 0; i < unique.size(); i++){
        count += hashmap[unique[i]];
        if(count >= keys[k]){
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
    // std::cout << "Std Sort ran in "<<  time << " microseconds." << std::endl;
}