#include <SDL2/SDL.h>
#include <glog/logging.h>
#include <chrono>
#include "scope_guard.h"
#include "states/state_stack.h"
#include "util.h"

int main(int, char** argv) {
  using namespace kuru;
  google::InitGoogleLogging(argv[0]);

  CHECK_SDL(SDL_Init(SDL_INIT_EVERYTHING) == 0);
  const scope_guard sdl_quit(SDL_Quit);

  const sdl_ptr<SDL_Window> window(
      SDL_CreateWindow("kuru", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       640, 480, SDL_WINDOW_SHOWN),
      SDL_DestroyWindow);
  CHECK_SDL(window);

  const sdl_ptr<SDL_Renderer> renderer(
      SDL_CreateRenderer(window.get(), -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
      SDL_DestroyRenderer);
  CHECK_SDL(renderer);

  std::chrono::milliseconds last_time(SDL_GetTicks());
  StateStack states;
  states.push<SampleState>();
  SDL_Event event;
  while (true) {
    const std::chrono::milliseconds now(SDL_GetTicks());
    const auto delta = now - last_time;
    last_time = now;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        return 0;
      }
      states.handle_event(event, delta);
    }

    SDL_RenderClear(renderer.get());
    states.render(*renderer);
    SDL_RenderPresent(renderer.get());
  }
}
