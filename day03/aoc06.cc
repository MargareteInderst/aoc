#include <iostream>
#include <string>
#include <sstream>

std::string active(const std::string& input){

  std::string sequence;

  int pos = 0;

  bool doing = true;

  while((doing == true && input.find("don't()", pos) != std::string::npos) || (doing == false && input.find("do()", pos) != std::string::npos)){

    
    if(doing == true){

      int newpos = input.find("don't()", pos);
      sequence.append(input, pos, newpos-pos);//wonky

      doing = false;
      pos = newpos+7;
    }
    else{

      int newpos = input.find("do()", pos);
      doing = true;
      pos = newpos+4;
    }
  }

  if(doing == true){

    sequence.append(input.begin() + pos, input.end());
  }

  return sequence;
}

int main() {
  int sum = 0;

  std::string input;
  
  while(std::getline(std::cin, input)){

    std::string sequence = active(input);
    //std::string sequence = input;

    
    char li;
    char lii;
    char liii;
    char ri;
    char rii;
    char riii;

    std::string::iterator it = sequence.begin();

    while (it != sequence.end()) {
      if (*it == 'm' && it + 1 != sequence.end()) {
        ++it;
        if (*it == 'u' && it + 1 != sequence.end()) {
          ++it;

          if (*it == 'l' && it + 1 != sequence.end()) {
            ++it;

            if (*it == '(' && it + 1 != sequence.end()) {
              ++it;

              if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                li = *it;
                ++it;

                if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                  lii = *it;
                  ++it;

                  if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                    liii = *it;
                    ++it;

                    if (*it == ',' && it + 1 != sequence.end()) {
                      ++it;

                      if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                        ri = *it;
                        ++it;

                        if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                          rii = *it;
                          ++it;

                          if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                            riii = *it;
                            ++it;

                            // mul(abc,xyz)
                            if (*it == ')') {
                              int numl = (li - 48) * 100 + (lii - 48) * 10 + (liii - 48);
                              int numr = (ri - 48) * 100 + (rii - 48) * 10 + (riii - 48);

                              sum += (numl * numr);
                            }

                          }  // mul(abc,xy)
                          else if (*it == ')') {
                            
                            int numl = (li - 48) * 100 + (lii - 48) * 10 + (liii - 48);
                            int numr = (ri - 48) * 10 + (rii - 48);

                            sum += (numl * numr);
                          }

                        }  // mul(abc,x)
                        else if (*it == ')') {

                          int numl = (li - 48) * 100 + (lii - 48) * 10 + (liii - 48);
                          int numr = (ri - 48);

                          sum += (numl * numr);
                        }
                      }
                    }

                  }  // mul(ab,...
                  else if (*it == ',' && it + 1 != sequence.end()) {
                    ++it;

                    if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                      ri = *it;
                      ++it;

                      if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                        rii = *it;
                        ++it;

                        if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                          riii = *it;
                          ++it;

                          // mul(ab,xyz)
                          if (*it == ')') {
                            
                            int numl = (li - 48) * 10 + (lii - 48);
                            int numr = (ri - 48) * 100 + (rii - 48) * 10 + (riii - 48);

                            sum += (numl * numr);
                          }

                        }  // mul(ab,xy)
                        else if (*it == ')') {

                          int numl = (li - 48) * 10 + (lii - 48);
                          int numr = (ri - 48) * 10 + (rii - 48);

                          sum += (numl * numr);
                        }

                      }  // mul(ab,x)
                      else if (*it == ')') {

                        int numl = (li - 48) * 10 + (lii - 48);
                        int numr = (ri - 48);

                        sum += (numl * numr);
                      }
                    }
                  }

                }  // mul(a,...
                else if (*it == ',' && it + 1 != sequence.end()) {
                  ++it;

                  if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                    ri = *it;
                    ++it;

                    if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                      rii = *it;
                      ++it;

                      if (*it >= '0' && *it <= '9' && it + 1 != sequence.end()) {
                        riii = *it;
                        ++it;

                        // mul(a,xyz)
                        if (*it == ')') {
                          int numl = (li - 48);
                          int numr = (ri - 48) * 100 + (rii - 48) * 10 + (riii - 48);

                          sum += (numl * numr);
                        }

                      }  // mul(a,xy)
                      else if (*it == ')') {

                        int numl = (li - 48);
                        int numr = (ri - 48) * 10 + (rii - 48);

                        sum += (numl * numr);
                      }
                    }  // mul(a,x)
                    else if (*it == ')') {

                      int numl = (li - 48);
                      int numr = (ri - 48);

                      sum += (numl * numr);
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++it;
    }
  }

  //don't()mul(15,10)do()do()don't()mul(5,5)
  std::cout << "sum " << sum << std::endl;

  return 0;
}