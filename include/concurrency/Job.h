#ifndef CONCURRENCY_JOB_H
#define CONCURRENCY_JOB_H
#include <functional>
namespace concurrency {
#if __cpp_lib_move_only_function
  using default_function_type = std::move_only_function<void()>;
#else
  using default_function_type = std::function<void()>;
#endif

  /**
   * @tparam FunctionType type to be run by the runner. Mostly void function
   * @brief Job descriptor to be run by the workers
   */
  template <typename FunctionType = default_function_type>
  requires std::invocable<FunctionType> && std::is_same_v<void, std::invoke_result_t<FunctionType>>
  struct Job {
  };
}  // namespace concurrency
#endif  // CONCURRENCY_JOB_H
