#ifndef CONCURRENCY_SCHEDULER_H
#define CONCURRENCY_SCHEDULER_H
#include <thread>
namespace concurrency {
  class Scheduler {
  public:
    static auto ConcurrencyLevel() -> uint32_t { return std::thread::hardware_concurrency(); }
  };
}  // namespace concurrency
#endif  // CONCURRENCY_SCHEDULER_H
