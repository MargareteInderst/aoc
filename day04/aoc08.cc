#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// we assume that the input is given with the same number of characters for each
// line

int diagonal(std::vector<std::string>& input) {
  int sum = 0;

  // i rows
  for (unsigned i = 0; i < input.size() - 2; ++i) {
    // j columns
    for (unsigned j = 0; j < input.at(0).size() - 2; ++j) {
      if (input.at(i).at(j) == 'M' && input.at(i + 1).at(j + 1) == 'A' &&
          input.at(i + 2).at(j + 2) == 'S') {
        if (input.at(i + 2).at(j) == 'M' && input.at(i).at(j + 2) == 'S') {
          ++sum;
        } else if (input.at(i + 2).at(j) == 'S' &&
                   input.at(i).at(j + 2) == 'M') {
          ++sum;
        }
      } else if (input.at(i).at(j) == 'S' && input.at(i + 1).at(j + 1) == 'A' &&
                 input.at(i + 2).at(j + 2) == 'M') {
        if (input.at(i + 2).at(j) == 'M' && input.at(i).at(j + 2) == 'S') {
          ++sum;
        } else if (input.at(i + 2).at(j) == 'S' &&
                   input.at(i).at(j + 2) == 'M') {
          ++sum;
        }
      }
    }
  }

  return sum;
}

int horizontal(std::vector<std::string>& input) {
  int sum = 0;

  // i rows
  for (unsigned i = 1; i < input.size() - 1; ++i) {
    // j columns
    for (unsigned j = 0; j < input.at(0).size() - 2; ++j) {
      if (input.at(i).at(j) == 'M' && input.at(i).at(j + 1) == 'A' &&
          input.at(i).at(j + 2) == 'S') {
        if (input.at(i - 1).at(j + 1) == 'M' &&
            input.at(i + 1).at(j + 1) == 'S') {
          ++sum;
        } else if (input.at(i - 1).at(j + 1) == 'S' &&
                   input.at(i + 1).at(j + 1) == 'M') {
          ++sum;
        }
      } else if (input.at(i).at(j) == 'S' && input.at(i).at(j + 1) == 'A' &&
                 input.at(i).at(j + 2) == 'M') {
        if (input.at(i - 1).at(j + 1) == 'M' &&
            input.at(i + 1).at(j + 1) == 'S') {
          ++sum;
        } else if (input.at(i - 1).at(j + 1) == 'S' &&
                   input.at(i + 1).at(j + 1) == 'M') {
          ++sum;
        }
      }
    }
  }

  return sum;
}

int main() {
  std::vector<std::string> input;
  std::string line;

  while (std::getline(std::cin, line)) {
    input.push_back(line);
  }

  std::cout << horizontal(input) + diagonal(input) << std::endl;

  return 0;
}