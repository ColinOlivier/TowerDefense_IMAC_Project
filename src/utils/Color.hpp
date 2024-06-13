#pragma once
#include <functional>

struct Color {
    float _R{ 0.f };
    float _G{ 0.f };
    float _B{ 0.f };

    bool operator==(const Color&) const = default;
    int hash() const;
};

namespace std {
    template<>
    struct hash<Color> {
        size_t operator()(Color const& color) const {
            return color.hash();
        }
    };
}