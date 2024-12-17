#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int horizontal(std::vector<std::string>& input) {
  int sum = 0;

  // i goes through the rows
  for (unsigned i = 0; i < input.size(); ++i) {
    // j goes through the columns
    for (unsigned j = 0; j < input.at(0).size() - 3; ++j) {
      if (input.at(i).at(j) == 'X' && input.at(i).at(j + 1) == 'M' &&
          input.at(i).at(j + 2) == 'A' && input.at(i).at(j + 3) == 'S') {
        ++sum;
      } else if (input.at(i).at(j) == 'S' && input.at(i).at(j + 1) == 'A' &&
                 input.at(i).at(j + 2) == 'M' && input.at(i).at(j + 3) == 'X') {
        ++sum;
      }
    }
  }

  return sum;
}

int diagonalright(std::vector<std::string>& input) {
  int sum = 0;

  // i goes through the rows
  for (unsigned i = 0; i < input.size() - 3; ++i) {
    // j goes through the columns
    for (unsigned j = 0; j < input.at(i).size() - 3; ++j) {
      if (input.at(i).at(j) == 'X' && input.at(i + 1).at(j + 1) == 'M' &&
          input.at(i + 2).at(j + 2) == 'A' &&
          input.at(i + 3).at(j + 3) == 'S') {
        ++sum;
      } else if (input.at(i).at(j) == 'S' && input.at(i + 1).at(j + 1) == 'A' &&
                 input.at(i + 2).at(j + 2) == 'M' &&
                 input.at(i + 3).at(j + 3) == 'X') {
        ++sum;
      }
    }
  }

  return sum;
}

int diagonalleft(std::vector<std::string>& input) {
  int sum = 0;

  // i goes through the rows
  for (unsigned i = 0; i < input.size() - 3; ++i) {
    // j goes through the columns
    for (unsigned j = 3; j < input.at(i).size(); ++j) {
      if (input.at(i).at(j) == 'X' && input.at(i + 1).at(j - 1) == 'M' &&
          input.at(i + 2).at(j - 2) == 'A' &&
          input.at(i + 3).at(j - 3) == 'S') {
        ++sum;
      } else if (input.at(i).at(j) == 'S' && input.at(i + 1).at(j - 1) == 'A' &&
                 input.at(i + 2).at(j - 2) == 'M' &&
                 input.at(i + 3).at(j - 3) == 'X') {
        ++sum;
      }
    }
  }

  return sum;
}

int vertical(std::vector<std::string>& input) {
  int sum = 0;

  // i goes through the rows
  for (unsigned i = 0; i < input.size() - 3; ++i) {
    // j goes through the columns
    for (unsigned j = 0; j < input.at(i).size(); ++j) {
      if (input.at(i).at(j) == 'X' && input.at(i + 1).at(j) == 'M' &&
          input.at(i + 2).at(j) == 'A' && input.at(i + 3).at(j) == 'S') {
        ++sum;
      } else if (input.at(i).at(j) == 'S' && input.at(i + 1).at(j) == 'A' &&
                 input.at(i + 2).at(j) == 'M' && input.at(i + 3).at(j) == 'X') {
        ++sum;
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

  std::cout << horizontal(input) + diagonalright(input) + diagonalleft(input) +
                   vertical(input)
            << std::endl;

  return 0;
}