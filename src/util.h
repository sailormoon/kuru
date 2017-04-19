#include <SDL2/SDL.h>
#include <glog/logging.h>
#include <memory>

#ifndef UTIL_H_
#define UTIL_H_

namespace spin {
#define SDL_CHECK(PTR_) CHECK(PTR_) << SDL_GetError()

template <class T>
using sdl_ptr = std::unique_ptr<T, void (*)(T*)>;
}  // namespace spin

#endif  // UTIL_H
