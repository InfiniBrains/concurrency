#ifndef CONCURRENCY_JOB_H
#define CONCURRENCY_JOB_H
#include <concepts>
#include <functional>

// todo: types of jobs: joinable, detached, repeatable, future result wrap, pausable or stoppable
// https://github.com/ConorWilliams/Threadpool
// priority

namespace concurrency {

  /**
   * @brief default function type "function<void()>" will be used if dont provided
   */
#if __cpp_lib_move_only_function
  using default_function_type = std::move_only_function<void()>;
#else
  using default_function_type = std::function<void()>;
#endif

  template <typename T = default_function_type>
  concept InvocableJob = requires {
    // todo: restrict this to not accept futures neither create another future job
    std::is_invocable_v<T>&& std::is_same_v<void, std::invoke_result_t<T>>;
  };

  /**
   * @tparam T type to be run by the runner. Mostly void function
   * @brief Job descriptor to be run by the workers
   */
  template <InvocableJob T = default_function_type> struct Job {};
}  // namespace concurrency
#endif  // CONCURRENCY_JOB_H
