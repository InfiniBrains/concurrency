#ifndef CONCURRENCY_RUNNINGSTATE_H
#define CONCURRENCY_RUNNINGSTATE_H
namespace concurrency {
  /**
   * @brief The states of the worker
   */
  enum class RunningState {
    /**
     * @brief it is doing nothing
     */
    Stopped,
    /**
     * @brief it is running
     */
    Running,
    /**
     * @brief pause is requested
     */
    PauseRequested,
    /**
     * it is paused
     */
    Paused,
    /**
     * @brief it is waiting for time or resource. Mostly for non blocking jobs and swappable
     * contexts. Coroutines(?).
     */
    Waiting,
  };
}  // namespace concurrency
#endif  // CONCURRENCY_RUNNINGSTATE_H
