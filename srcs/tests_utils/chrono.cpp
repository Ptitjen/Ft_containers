#include "chrono.hpp"

#include <iomanip>
#include <iostream>

#include "tests_utils.hpp"

Chrono::Chrono(std::string const &first, std::string const &last)
    : m_first_name(first), m_last_name(last) {
  m_start = (struct timespec){0, 0};
  m_first = (struct timespec){0, 0};
  m_last = (struct timespec){0, 0};
}

Chrono::~Chrono() {}

void Chrono::begin() {
  clock_gettime(CLOCK_MONOTONIC, &m_start);
  std::ios_base::sync_with_stdio(false);
}

void Chrono::stop() {
  if (m_first.tv_sec == 0 && m_first.tv_nsec == 0) {
    clock_gettime(CLOCK_MONOTONIC, &m_first);
  } else if (m_last.tv_sec == 0 && m_last.tv_nsec == 0) {
    clock_gettime(CLOCK_MONOTONIC, &m_last);
  }
  if (m_last.tv_sec != 0 && m_last.tv_nsec != 0) {
    printDiff(m_start, m_first, m_first_name);
    double time_taken1 = (m_first.tv_sec - m_start.tv_sec) * 1e9;  // NOLINT
    time_taken1 =
        (time_taken1 + (m_first.tv_nsec - m_start.tv_nsec)) * 1e-9;  // NOLINT
    printDiff(m_first, m_last, m_last_name);
    double time_taken2 = (m_last.tv_sec - m_first.tv_sec) * 1e9;  // NOLINT
    time_taken2 =
        (time_taken2 + (m_last.tv_nsec - m_first.tv_nsec)) * 1e-9;  // NOLINT
    if (time_taken1 / time_taken2 < 20)
      std::cout << BOLDGREEN "Perf OK";
    else
      std::cout << BOLDRED "Perf KO";
    std::cout << END " x " << time_taken1 / time_taken2 << std::endl;
  }
}

void Chrono::printDiff(struct timespec begin, struct timespec end,
                       std::string const &name) {
  double time_taken;
  time_taken = (end.tv_sec - begin.tv_sec) * 1e9;                    // NOLINT
  time_taken = (time_taken + (end.tv_nsec - begin.tv_nsec)) * 1e-9;  // NOLINT
  (void)name;
  // std::cout << "Time taken by ";
  // std::cout << std::left
  //           << std::setw(std::max(m_first_name.size(), m_last_name.size()))
  //           << std::setfill(' ') << name;
  // std::cout << " -> " << std::fixed << time_taken << " sec" << std::endl;
}