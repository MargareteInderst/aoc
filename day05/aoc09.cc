#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

//i need to change getupperInput and makeorder because they assume that we have a input where we get informations for every combination
//for example 11|22 22|33 11|33 instead of just 11|22 22|33

std::vector<int> getupperInput(){

  std::string line;

  std::vector<int> upperInput;

  while(std::getline(std::cin, line)){
    
    if(line.empty()){
      break;
    }
    //std::cerr << line << std::endl;
    upperInput.push_back(std::stoi(line));    
  }

  /*
  for(unsigned i = 0; i < upperInput.size(); ++i){
    std::cerr << upperInput.at(i) << " \n";
  }
  */

 return upperInput;
}

std::vector<std::vector<int>> getlowerInput(){

  std::string line;

  std::vector<std::vector<int>> lowerInput;

  std::vector<int> row;

  unsigned i = 0;

  while(std::getline(std::cin, line)){
    while(line.empty() != true){
      
      row.push_back(std::stoi(line));

      //std::cerr << std::stoi(line) << std::endl;

      line.erase(0, 3);
    }
    lowerInput.push_back(row);
    ++i;
    row.clear();
  }

  /*
  for(unsigned i = 0; i < lowerInput.size(); ++i){
    for(unsigned j = 0; j < lowerInput.at(i).size(); ++j){
    
      std::cerr << lowerInput.at(i).at(j) << " ";
    }
    std::cerr << std::endl;
  }
  */

 return lowerInput;
}

int numberofpages(std::vector<int>& upperInput){

  int n = (2 + sqrt(1+8*upperInput.size()))/2;

  return n;
}

std::vector<int> makeorder(std::vector<int>& upperInput, int n){

  std::vector<int> order(n,0);

  int c;

  //sehr ineffizient
  for(unsigned i = 0; i < upperInput.size(); ++i){

    c = std::count(upperInput.begin(), upperInput.end(), upperInput.at(i));

    order.at(n-c-1) = upperInput.at(i);
  }

  
  for(unsigned i = 0; i < order.size(); ++i){
    
    std::cerr << order.at(i) << " ";
  }
  std::cerr << std::endl;
  

  return order;
}

int makeSum(std::vector<int>& order, std::vector<std::vector<int>>& lowerInput){

  int sum = 0;

  bool correct = true;

  //iterates through all rows
  for(unsigned i = 0; i < lowerInput.size(); ++i){
    //iterates through all columns
    for(unsigned j = 0; j < lowerInput.at(i).size()-1; ++j){

      if(order.at(order.size()-1) == 0 && std::find(order.begin(), order.end(), lowerInput.at(i).at(j)) == order.end()){
        order.at(order.size()-1) = lowerInput.at(i).at(j);
      }
      else if(order.at(order.size()-1) == 0 && std::find(order.begin(), order.end(), lowerInput.at(i).at(j+1)) == order.end()){
        order.at(order.size()-1) = lowerInput.at(i).at(j+1);
      }

      if(std::find(order.begin(), order.end(), lowerInput.at(i).at(j)) < std::find(order.begin(), order.end(), lowerInput.at(i).at(j+1))){
        continue;
      }
      correct = false;
      break;
    }

    if(correct){
      int middle = lowerInput.at(i).at((lowerInput.at(i).size())/2);
      sum += middle;
      //std::cerr << middle << std::endl;
    }
    correct = true;
  }

  return sum;
}

int main(){

  std::vector<int> upperInput = getupperInput();

  std::vector<std::vector<int>> lowerInput = getlowerInput();

  int n = numberofpages(upperInput);

  std::vector<int> order = makeorder(upperInput, n);

  int sum = makeSum(order, lowerInput);

  std::cout << sum << std::endl;
  
  return 0;
}