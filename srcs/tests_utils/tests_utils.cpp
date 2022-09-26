#include "tests_utils.hpp"

bool operator==(const bli& x, const bli& y) {
  return ((x.int_ == y.int_) && (x.char_ == y.char_));
}

std::ostream& operator<<(std::ostream& o, bli const& rhs) {
  o << rhs.char_ << " " << rhs.int_;
  return o;
}