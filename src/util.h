#pragma once
#include <SDL2/SDL.h>
#include <glog/logging.h>
#include <memory>

namespace spin {
#define CHECK_SDL(PTR_) CHECK(PTR_) << SDL_GetError()

template <class T>
using sdl_ptr = std::unique_ptr<T, void (*)(T*)>;
}  // namespace spin
