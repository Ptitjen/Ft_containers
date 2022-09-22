#ifndef CHRONO_HPP
#define CHRONO_HPP

#include <sys/time.h>

#include <string>

class Chrono {
  struct timespec m_start, m_first, m_last;
  std::string m_first_name, m_last_name;

  void printDiff(struct timespec begin, struct timespec end,
                 std::string const &name);

 public:
  Chrono(std::string const &first, std::string const &last);
  ~Chrono();

  void begin();
  void stop();
};

#endif
