#ifndef CONCURRENCY_SCHEDULER_H
#define CONCURRENCY_SCHEDULER_H
#include <memory>
#include <thread>
#include <vector>

#include "Worker.h"

// todo:
//  add more worker threads if there is job to do and all threads are locked in a wait state
//  destroy workers if no more job arrives after a timeout without jobs
//  creation and destruction strategy as LIFO (probably FIFO is not a good idea)

// ref: https://github.com/stlab/libraries/blob/main/stlab/concurrency/default_executor.hpp
// ref: https://github.com/Tyler-Hardin/thread_pool/blob/master/thread_pool.hpp
// ref:
// https://blog.molecular-matters.com/2015/08/24/job-system-2-0-lock-free-work-stealing-part-1-basics/
namespace concurrency {
  class Scheduler {
  public:
    /**
     * @return Singleton instance of the scheduler
     */
    static Scheduler& Instance() {
      static Scheduler singleton;
      return singleton;
    }
    // todo: check if this value is static initialized in the moment the program starts
    /**
     * @brief the MainThreadId. Useful to check who is running the job.
     */
    const static inline auto MainThreadId = std::this_thread::get_id();
    /**
     * @return the number of concurrent hardware threads available. usually is the number of
     * cpucores*2
     */
    static auto ConcurrencyLevel() { return std::thread::hardware_concurrency(); }
    size_t RunningWorkersQuantity();

  private:
    Scheduler();
    Scheduler(Scheduler const&) = delete;             // copy ctor
    Scheduler(Scheduler&&) = delete;                  // move ctor
    Scheduler& operator=(Scheduler const&) = delete;  // copy assignment
    Scheduler& operator=(Scheduler&&) = delete;       // move assignment
    // todo: create different types of workers.
    //  ex: the default workers should not accept jobs with thread pause or any kind of waiting.
    /**
     * @brief the default workers.
     */
    std::vector<std::shared_ptr<Worker>> workers;  // probably a unique would be better
    // todo: resizable number of workers
  };
}  // namespace concurrency
#endif  // CONCURRENCY_SCHEDULER_H
