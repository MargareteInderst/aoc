#include <iostream>
#include <vector>
#include <sstream>

bool safe(std::vector<int> report){

    bool inc;

    if(report.size() == 1){
        return true;
    }

    if(report.at(0) < report.at(1)){
        inc = true;        
    }
    else if(report.at(0) > report.at(1)){
        inc = false;
    }
    else{ 
        return false;
    }

    for(unsigned i = 1; i < report.size(); ++i){
        
        if(inc){
            
            if(report.at(i)-report.at(i-1) > 3 || report.at(i)-report.at(i-1) <= 0){
                
                return false;
            }
        }
        else{

            if(report.at(i-1)-report.at(i) > 3 || report.at(i-1)-report.at(i) <= 0){

                return false;
            }
        }
    }


    return true;
}


int main(){

    std::vector<int> report;
    int sum = 0;
    std::string line;
    std::string i;


    for(;std::getline(std::cin,line);){

        std::stringstream ss(line);

        while(ss >> i){

            report.push_back(stoi(i));
        }

        if(safe(report)){
            
            ++sum;
        }
        else{

            std::vector<int> original = report;

            for(unsigned i = 0; i < report.size(); ++i){

                report.erase(report.begin()+i);
                if(safe(report)){
                    ++sum;
                    break;
                }

                report = original;
            }
        }

        report.clear();
    }
    
    std::cout << "sum " << sum << " " << std::endl;


    return 0;
}