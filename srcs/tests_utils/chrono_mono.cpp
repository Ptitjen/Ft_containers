#include "chrono_mono.hpp"

#include <iomanip>
#include <iostream>

#include "tests_utils.hpp"

ChronoMono::ChronoMono() {
  m_start = (struct timespec){0, 0};
  m_stop = (struct timespec){0, 0};
}

ChronoMono::~ChronoMono() {}

void ChronoMono::begin() {
  clock_gettime(CLOCK_MONOTONIC, &m_start);
  std::ios_base::sync_with_stdio(false);
}

void ChronoMono::stop() {
  if (m_stop.tv_sec == 0 && m_stop.tv_nsec == 0) {
    clock_gettime(CLOCK_MONOTONIC, &m_stop);
  }
  double time_taken = (m_stop.tv_sec - m_start.tv_sec) * 1e9;  // NOLINT
  time_taken =
      (time_taken + (m_stop.tv_nsec - m_start.tv_nsec)) * 1e-9;  // NOLINT
  std::cout << BOLDCYAN "Time taken: " END << time_taken << std::endl;
}
