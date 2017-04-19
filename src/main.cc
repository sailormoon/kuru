#include <SDL2/SDL.h>
#include <memory>

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window(
      SDL_CreateWindow("spin!", 100, 100, 640, 480, SDL_WINDOW_SHOWN),
      SDL_DestroyWindow);
  if (!window) {
    return -1;
  }

  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer(
      SDL_CreateRenderer(window.get(), -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC),
      SDL_DestroyRenderer);
  if (!renderer) {
    return -1;
  }

  for (int i = 0; i < 3; ++i) {
    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
    SDL_Delay(1000);
  }
  SDL_Quit();
}
