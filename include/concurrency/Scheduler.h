#ifndef CONCURRENCY_SCHEDULER_H
#define CONCURRENCY_SCHEDULER_H
#include <thread>
namespace concurrency {
  class Scheduler {
    const unsigned int &number_of_threads = std::thread::hardware_concurrency();
  };
}  // namespace concurrency
#endif  // CONCURRENCY_SCHEDULER_H
