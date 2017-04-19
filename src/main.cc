#include <SDL2/SDL.h>
#include "glog/logging.h"
#include "util.h"

int main() {
  using namespace spin;
  SDL_Init(SDL_INIT_EVERYTHING);

  const sdl_ptr<SDL_Window> window(
      SDL_CreateWindow("spin!", 100, 100, 640, 480, SDL_WINDOW_SHOWN),
      SDL_DestroyWindow);
  SDL_CHECK(window);

  const sdl_ptr<SDL_Renderer> renderer(
      SDL_CreateRenderer(window.get(), -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
      SDL_DestroyRenderer);
  SDL_CHECK(renderer);

  for (int i = 0; i < 3; ++i) {
    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
    SDL_Delay(1000);
  }
  SDL_Quit();
}
