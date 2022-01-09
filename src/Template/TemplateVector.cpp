#ifndef TEMPLATEVECTOR_H
#define TEMPLATEVECTOR_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

// print 1D vector
// Precondition:
// Postcondition: prints 1D vector
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  int col = 0;
  for (auto elem : vec) {
    os << std::left << std::setw(5) << elem << " ";
    // print 10 columns per line
    if (++col % 10 == 0) {
      std::cout << std::endl;
    }
  }
  return os;
} // -----------------------------------------------------------------------------

// find element in 1D vector
// Precondition: vec is a 1D vector, elem is an element of type T
// Postcondition: returns true if element is found
template <typename T> bool find(const std::vector<T> &vec, const T &elem) {
  return std::find(vec.begin(), vec.end(), elem) != vec.end();
} // -----------------------------------------------------------------------------

#endif // TEMPLATEVECTOR_H
