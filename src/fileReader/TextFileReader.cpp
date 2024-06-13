#include "fileReader/TextFileReader.hpp"
#include <iostream>
#include <fstream> 

std::vector<std::string> TextFileReader::readTextFile(std::string filename) const {
    std::ifstream inputFile(filename);

    // Check if the file is successfully opened 
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return {};
    }

    std::string line;
    std::vector<std::string> vectorLine;
    // Read each line of the file 
    while (getline(inputFile, line)) {
        vectorLine.push_back(line);
    }

    // Close the file 
    inputFile.close();

    return vectorLine;
}
