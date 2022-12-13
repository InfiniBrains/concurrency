#include <concurrency/Worker.h>

#include <thread>
using namespace concurrency;
uint64_t Worker::Id() { return id; }
Worker::Worker() {
  static std::atomic<std::uint32_t> uid{0};
  id = ++uid;
}
