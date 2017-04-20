#pragma once
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
  void handle_event(const SDL_Event& event) const {
    states_.back()->handle_event(event);
  }
  void update(const std::chrono::milliseconds delta_time) {
    states_.back()->update(delta_time);
  }

 private:
  std::vector<std::unique_ptr<State>> states_;
};
}  // namespace kuru
