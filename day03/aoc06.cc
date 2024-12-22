#include <iostream>
#include <sstream>
#include <string>
#include <regex>

std::string active(const std::string& input) {
  std::string sequence;

  bool doing = true;

  for (unsigned i = 0; i < input.size(); ++i) {
    std::string substring = input.substr(i);

    if (doing == true && substring.starts_with("don't()") == false) {
      sequence.push_back(input.at(i));
    } else if (doing == true && substring.starts_with("don't()") == true) {
      doing = false;
    } else if (doing == false && substring.starts_with("do()") == true) {
      doing = true;
    } else {
      continue;
    }
  }
  std::cerr << sequence << std::endl;
  return sequence;
}


std::string getinput(){
  std::string input;

  char c;
  while(std::cin.get(c)){
    input.push_back(c);
  }
  return input;
}


/*
int sum(std::string& sq){

  int s = 0;
  std::regex pattern("^mul\\([0-999]\\,[0-999]\\)");

  for(unsigned i = 0; i < sq.size(); ++i){

    std:: string substring = sq.substr(i);

    if(std::regex_match(substring, pattern)){
      int x = std::stoi()
    }
  }






  
  return s;
}
*/




int main() {
  int s = 0;

  std::string input = getinput();
  std::cerr << input << std::endl;

  //std::string sequence = input;
  std::string sequence = active(input);

  std::cout << sequence << std::endl;
  //s = sum(sequence);
  
  //std::cout << s << std::endl;
  return 0;
}


