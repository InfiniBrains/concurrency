#include <concurrency/Scheduler.h>

#include <span>
using namespace concurrency;

Scheduler::Scheduler() {
  auto threads = ConcurrencyLevel();
  while (threads--) workers.push_back(std::make_shared<Worker>());
}
size_t Scheduler::RunningWorkersQuantity() {
  // todo: count the number of workers by state running
  return workers.size();
}
