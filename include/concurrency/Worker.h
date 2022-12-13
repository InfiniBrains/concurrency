#ifndef CONCURRENCY_WORKER_H
#define CONCURRENCY_WORKER_H

// todo: worker should know that if should stop
//   job should be pausable(?) coroutines?

#include <string>
namespace concurrency {
  class Worker {
    std::string name;
  };
}  // namespace concurrency
#endif  // CONCURRENCY_WORKER_H
