#include <concurrency/Scheduler.h>
#include <concurrency/version.h>
#include <doctest/doctest.h>

#include <string>

TEST_CASE("Concurrency") {
  using namespace concurrency;

  CHECK(Scheduler::Instance().RunningWorkersQuantity() == Scheduler::Instance().ConcurrencyLevel());
}

TEST_CASE("Concurrency version") {
  // todo: get this from git. automate cmake version change
  static_assert(std::string_view(CONCURRENCY_VERSION) == std::string_view("1.0"));
  CHECK(std::string(CONCURRENCY_VERSION) == std::string("1.0"));
}
