#include <iostream>
#include <string>


int main() {
  int sum = 0;

  char m;
  char u;
  char l;
  char bl;
  char li;
  char lii;
  char liii;
  char c;
  char ri;
  char rii;
  char riii;
  char br;

  for (; std::cin.get(m);) {
    if (m == 'm') {
      std::cin.get(u);

      if (u == 'u') {
        std::cin.get(l);

        if (l == 'l') {
          std::cin.get(bl);

          if (bl == '(') {
            std::cin.get(li);

            if (li >= '0' && li <= '9') {
              std::cin.get(lii);

              if (lii >= '0' && lii <= '9') {
                std::cin.get(liii);

                if (liii >= '0' && liii <= '9') {
                  std::cin.get(c);

                  if (c == ',') {
                    std::cin.get(ri);

                    if (ri >= '0' && ri <= '9') {
                      std::cin.get(rii);

                      if (rii >= '0' && rii <= '9') {
                        std::cin.get(riii);

                        if (riii >= '0' && riii <= '9') {
                          std::cin.get(br);

                          // mul(abc,xyz)
                          if (br == ')') {
                            int numl =
                                (li - 48) * 100 + (lii - 48) * 10 + (liii - 48);
                            int numr =
                                (ri - 48) * 100 + (rii - 48) * 10 + (riii - 48);

                            sum += (numl * numr);
                          }

                        }  // mul(abc,xy)
                        else if (riii == ')') {
                          br = riii;

                          int numl =
                              (li - 48) * 100 + (lii - 48) * 10 + (liii - 48);
                          int numr = (ri - 48) * 10 + (rii - 48);

                          sum += (numl * numr);
                        }

                      }  // mul(abc,x)
                      else if (rii == ')') {
                        br = rii;

                        int numl =
                            (li - 48) * 100 + (lii - 48) * 10 + (liii - 48);
                        int numr = (ri - 48);

                        sum += (numl * numr);
                      }
                    }
                  }

                }  // mul(ab,...
                else if (liii == ',') {
                  c = liii;

                  std::cin.get(ri);

                  if (ri >= '0' && ri <= '9') {
                    std::cin.get(rii);

                    if (rii >= '0' && rii <= '9') {
                      std::cin.get(riii);

                      if (riii >= '0' && riii <= '9') {
                        std::cin.get(br);

                        // mul(ab,xyz)
                        if (br == ')') {
                          int numl = (li - 48) * 10 + (lii - 48);
                          int numr =
                              (ri - 48) * 100 + (rii - 48) * 10 + (riii - 48);

                          sum += (numl * numr);
                        }

                      }  // mul(ab,xy)
                      else if (riii == ')') {
                        br = riii;

                        int numl = (li - 48) * 10 + (lii - 48);
                        int numr = (ri - 48) * 10 + (rii - 48);

                        sum += (numl * numr);
                      }

                    }  // mul(ab,x)
                    else if (rii == ')') {
                      br = rii;

                      int numl = (li - 48) * 10 + (lii - 48);
                      int numr = (ri - 48);

                      sum += (numl * numr);
                    }
                  }
                }

              }  // mul(a,...
              else if (lii == ',') {
                c = lii;

                std::cin.get(ri);

                if (ri >= '0' && ri <= '9') {
                  std::cin.get(rii);

                  if (rii >= '0' && rii <= '9') {
                    std::cin.get(riii);

                    if (riii >= '0' && riii <= '9') {
                      std::cin.get(br);

                      // mul(a,xyz)
                      if (br == ')') {
                        int numl = (li - 48);
                        int numr =
                            (ri - 48) * 100 + (rii - 48) * 10 + (riii - 48);

                        sum += (numl * numr);
                      }

                    }  // mul(a,xy)
                    else if (riii == ')') {
                      br = riii;

                      int numl = (li - 48);
                      int numr = (ri - 48) * 10 + (rii - 48);

                      sum += (numl * numr);
                    }
                  }  // mul(a,x)
                  else if (rii == ')') {
                    br = rii;

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
  }

  std::cout << " " << sum << std::endl;

  return 0;
}