#ifndef CONCURRENCY_WORKER_H
#define CONCURRENCY_WORKER_H

// todo: worker should know that if should stop
//   job should be pausable(?) coroutines?

#include <string>
namespace concurrency {
  class Worker {
  public:
    Worker();
    /**
     * @brief the name of the worker. It should be used in conjunction with debug / inspection
     * techniques. Not unique guarantee is given. Do not use this as a key for searches
     */
    std::string name;

    /**
     * @brief the current id of the worker. This can be used as a key for searches
     * @return the current id of the worker.
     */
    uint64_t Id();

  private:
    uint64_t id;
  };
}  // namespace concurrency
#endif  // CONCURRENCY_WORKER_H
