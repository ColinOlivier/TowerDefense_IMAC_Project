#include "utils/Color.hpp"

int Color::hash() const {
    return _R + _G * 256 + _B * 256 * 256;
}