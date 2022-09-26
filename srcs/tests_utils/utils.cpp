#include "utils.hpp"

bli::bli() : int_(1), char_('a') {}
bli::bli(const int& i, const char& c)  // NOLINT
    : int_(i), char_(c) {}
bli::~bli(){};

bool operator==(const bli& x, const bli& y) {
  return ((x.int_ == y.int_) && (x.char_ == y.char_));
}

std::ostream& operator<<(std::ostream& o, bli const& rhs) {
  o << rhs.char_ << " " << rhs.int_;
  return o;
}