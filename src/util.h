#include <memory>

namespace spin {
template <class T>
using sdl_ptr = std::unique_ptr<T, void (*)(T*)>;
}  // namespace spin
