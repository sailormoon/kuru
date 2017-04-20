#pragma once
#include <functional>

namespace kuru {
struct scope_guard {
  template <class Callable>
  explicit scope_guard(Callable&& cleanup)
      : cleanup(std::forward<Callable>(cleanup)) {}
  ~scope_guard() { cleanup(); }
  scope_guard(const scope_guard& other) = delete;
  scope_guard& operator=(const scope_guard& other) = delete;

 private:
  const std::function<void()> cleanup;
};
}  // namespace kuru
