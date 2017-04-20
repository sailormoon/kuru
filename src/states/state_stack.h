#pragma once
#include <chrono>
#include <vector>
#include "state.h"

namespace kuru {
class StateStack {
 public:
  template <class T>
  void push() {
    states_.emplace_back(std::make_unique<T>());
  }
  void pop() { states_.pop_back(); }
  bool empty() const { return states_.empty(); }
  void render(SDL_Renderer& renderer) const {
    states_.back()->render(renderer);
  }
  void handle_event(const SDL_Event& event,
                    const std::chrono::milliseconds) const {
    states_.back()->handle_event(event);
  }

 private:
  std::vector<std::unique_ptr<State>> states_;
};
}  // namespace kuru
