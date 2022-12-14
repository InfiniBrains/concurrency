#ifndef CONCURRENCY_STEALINGDEQUE_H
#define CONCURRENCY_STEALINGDEQUE_H
#include <concepts>
#include <deque>
#include <mutex>
#include <optional>

// todo: priority

namespace concurrency {

  // todo: make one queue per worker
  // ref:
  // https://github.com/DeveloperPaul123/thread-pool/blob/master/include/thread_pool/thread_safe_queue.h
  // https://github.com/ConorWilliams/ConcurrentDeque/blob/main/include/riften/deque.hpp
  // ref: https://www.youtube.com/watch?v=zULU6Hhp42w
  /**
   * @brief Simple concept for the Lockable and Basic Lockable types as defined by the C++
   * standard.
   * @details See https://en.cppreference.com/w/cpp/named_req/Lockable and
   * https://en.cppreference.com/w/cpp/named_req/BasicLockable for details.
   */
  template <typename Lock>
  concept is_lockable = requires(Lock&& lock) {
    lock.lock();
    lock.unlock();
    { lock.try_lock() } -> std::same_as<bool>;
  };

  template <typename T, typename Lock = std::mutex>
  requires is_lockable<Lock>
  class StealingQueue {
  public:
    using value_type = T;
    using size_type = typename std::deque<T>::size_type;

    StealingQueue() = default;

    void push(T&& value) {
      std::lock_guard lock(mutex_);
      data_.push_back(std::forward<T>(value));
    }

    [[nodiscard]] bool empty() const {
      std::lock_guard lock(mutex_);
      return data_.empty();
    }

    [[nodiscard]] std::optional<T> pop() {
      std::lock_guard lock(mutex_);
      if (data_.empty()) return std::nullopt;

      auto front = std::move(data_.front());
      data_.pop_front();
      return front;
    }

    [[nodiscard]] std::optional<T> steal() {
      std::lock_guard lock(mutex_);
      if (data_.empty()) return std::nullopt;

      auto back = std::move(data_.back());
      data_.pop_back();
      return back;
    }

  private:
    // todo: improve
    // std::deque allocates memory when inserting elements and frees memory when erasing. In my
    // experience allocating or freeing memory while holding a lock is one of the bigger sources of
    // contention in parallel programs. Try to do the memory allocation/freeing outside of the
    // critical region.
    std::deque<T> data_{};
    // todo: improve the locking mechanism!
    mutable Lock mutex_{};
  };
}  // namespace concurrency
#endif  // CONCURRENCY_STEALINGDEQUE_H
