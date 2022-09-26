#ifndef CHRONO_MONO_HPP
#define CHRONO_MONO_HPP

#include <sys/time.h>

#include <string>

class ChronoMono {
  struct timespec m_start, m_stop;

 public:
  ChronoMono();
  ~ChronoMono();

  void begin();
  void stop();
};

#endif
