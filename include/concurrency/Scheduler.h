#ifndef CONCURRENCY_SCHEDULER_H
#define CONCURRENCY_SCHEDULER_H
#include <thread>

// todo:
//  add more worker threads if there is job to do and all threads are locked in a wait state
//  destroy workers if no more job arrives after a timeout without jobs
//  creation and destruction strategy as LIFO (probably FIFO is not a good idea)

// ref: https://github.com/stlab/libraries/blob/main/stlab/concurrency/default_executor.hpp
// ref:
// https://blog.molecular-matters.com/2015/08/24/job-system-2-0-lock-free-work-stealing-part-1-basics/
namespace concurrency {
  class Scheduler {
  public:
    static auto ConcurrencyLevel() -> uint32_t { return std::thread::hardware_concurrency(); }
  };
}  // namespace concurrency
#endif  // CONCURRENCY_SCHEDULER_H
