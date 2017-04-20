#pragma once
#include <SDL2/SDL.h>

namespace kuru {
class State {
 public:
  virtual void render(SDL_Renderer& renderer) = 0;
  virtual void handle_event(const SDL_Event& event) = 0;
};

class SampleState final : public State {
 public:
  void render(SDL_Renderer& renderer) {
    SDL_SetRenderDrawColor(&renderer, 128, 0, 0, 255);
  }
  void handle_event(const SDL_Event&) {}
};
}  // namespace kuru
