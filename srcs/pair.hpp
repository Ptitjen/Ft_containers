#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
template <class T1, class T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  T1 first;
  T2 second;

  pair(T1 f, T2 s) : first(f), second(s){};

  pair& operator=(const pair& other) {
    if (&other == this) return *this;
    first = other.first;
    second = other.second;
    return *this;
  };

  void swap(pair& other) {
    T1 tmp1 = first;
    T2 tmp2 = second;
    first = other.first;
    second = other.second;
    other.first = tmp1;
    other.first = tmp2;
  };
};

template <class T1, class T2>
void swap(pair<T1, T2>& x, pair<T1, T2>& y)  // NOLINT
{
  T1 tmp1 = x.first;
  T2 tmp2 = x.second;
  x.first = y.first;
  x.second = y.second;
  y.first = tmp1;
  y.first = tmp2;
};

template <class T1, class T2>
bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return x.first == y.first && x.second == y.second;
}

template <class T1, class T2>
bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return !(x == y);
}

template <class T1, class T2>
bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template <class T1, class T2>
bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return !(y < x);
}

template <class T1, class T2>
bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return y < x;
}

template <class T1, class T2>
bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y) {
  return !(x < y);
}
}  // namespace ft
#endif