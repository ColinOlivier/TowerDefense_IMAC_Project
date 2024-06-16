#pragma once

#include <filesystem>
#include <glm/glm.hpp>

std::filesystem::path make_absolute_path(std::filesystem::path const &path, bool check_path_exists = true);

template <glm::length_t N, typename T, glm::qualifier Q>
std::ostream &operator<<(std::ostream &os, glm::vec<N, T, Q> const &vec)
{
    os << "(";

    os << vec[0];
    for (size_t i{1}; i < N; ++i)
    {
        os << ", " << vec[i];
    }
    os << ")";
    return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &vec)
{
    if (vec.empty())
    {
        return os << "[]";
    }

    os << '[';
    for (size_t i{0}; i < vec.size() - 1; ++i)
    {
        os << vec[i] << ", ";
    }
    return os << vec.back() << ']';
}

struct Position
{
    double x{ 0 }, y{ 0 };
    Position& operator+=(const Position& pos);
};

bool operator==(Position const &begin, Position const &end);
Position operator*(Position const &begin, float const f);
Position operator*(float const f, Position const &position);
Position operator+(Position const &begin, Position const &end);
Position operator-(Position const &begin, Position const& end);

unsigned int getChebyshevDistance(Position const& begin, Position const& end);
