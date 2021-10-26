#include <iostream>
#include <boost/algorithm/string.hpp>
#include "IpReader.h"

StringVector IpReader::Read() {
    std::string l;
    auto result = std::make_unique<std::vector<std::string>>();

    while (std::getline(std::cin, l)) {
        result->push_back(l);
    }
    return result;
}