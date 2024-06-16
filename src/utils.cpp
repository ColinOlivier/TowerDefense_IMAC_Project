#include "utils.hpp"

#include <iostream>

std::filesystem::path make_absolute_path(std::filesystem::path const& path, bool check_path_exists)
{
    auto const res{ path.is_relative() ? CMAKE_SOURCE_DIR / path : path };

    if (check_path_exists && !std::filesystem::exists(res))
    {
        using namespace std::literals;
        auto const msg{ "Path \""s + res.string() + "\" does not exist. Make sure you didn't misspell it or made it relative to the wrong folder. All relative paths will be relative to the directory containing your CMakeLists.txt file." };
        std::cerr << msg << '\n';
        throw std::runtime_error{ msg };
    }

    return res;
}

bool operator==(Position const& begin, Position const& end)
{
    return { begin.x == end.x && begin.y == end.y };
}

Position operator*(Position const& position, float const f)
{
    return Position{ position.x * f, position.y * f };
}

Position operator*(float const f, Position const& position)
{
    return Position{ position.x * f, position.y * f };
}

Position operator+(Position const& begin, Position const& end)
{
    return Position{ begin.x + end.x, begin.y + end.y };
}

Position operator-(Position const& begin, Position const& end)
{
    return Position{ begin.x - end.x, begin.y - end.y };
}

unsigned int getChebyshevDistance(Position const& begin, Position const& end) {
    // TODO
    return 2;
}

Position& Position::operator+=(const Position& pos) {
    x += pos.x;
    y += pos.y;

    return *this;
}