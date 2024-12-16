#include <iostream>
#include <string>

std::string active(std::string& input){

  bool doing = true;

  std::string::size_type ix = 0;
  std::string::iterator it = input.end();

  while((doing == true && input.find("don't()") != std::string::npos) || (doing == false && input.find("do()", ix) != std::string::npos)){
    if(doing == true){
      if(it != input.end()){

        input.erase(it,it+4);
        ix = ix-*it;
      } 
      std::cerr << input << "\n";
      ix = input.find("don't()");
      it = input.begin() + ix;
      //std::cerr << *(it-1);
      doing = false;
    }
    else{
      //doing == false

      ix = input.find("do()");

      input.erase(it, input.begin()+ix);

      std::cerr << input << "\n";

      it = input.begin() + ix - *it;

      doing = true;
    }
  }
  

  if(doing == false){
    input.erase(it,input.end());
  }
  std::cerr << input << "\n";

  return input;  
}

int main() {
  int sum = 0;

  std::string input;

  std::cin >> input;

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

  //don't()mul(15,10)do()do()don't()mul(5,5)
  std::cout << "sum " << sum << std::endl;

  return 0;
}