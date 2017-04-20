#pragma once
#include <SDL2/SDL.h>
#include <chrono>
#include <cstdint>

namespace kuru {
class State {
 public:
  virtual void handle_event(const SDL_Event& event) = 0;
  virtual void update(const std::chrono::milliseconds delta_time) = 0;
  virtual void render(SDL_Renderer& renderer) = 0;
};

class SampleState final : public State {
 public:
  void handle_event(const SDL_Event&) {}
  void update(const std::chrono::milliseconds delta_time) {
    rectangle.x += delta_time.count() * direction;
    if (rectangle.x < 0 || rectangle.x > 640 - rectangle.w) direction *= -1;
  }
  void render(SDL_Renderer& renderer) {
    SDL_SetRenderDrawColor(&renderer, 128, 0, 0, 255);
    SDL_RenderFillRect(&renderer, &rectangle);
  }

 private:
  SDL_Rect rectangle{320, 240, 32, 32};
  std::int32_t direction = 1;
};
}  // namespace kuru
