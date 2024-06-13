#pragma once

#include <vector>
#include <string>

struct TextFileReader
{
    std::vector<std::string> readTextFile(std::string filename) const;
};
