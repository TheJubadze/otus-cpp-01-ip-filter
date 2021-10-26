#pragma once

#include <vector>
#include <string>
#include <memory>

using StringVector = std::unique_ptr<std::vector<std::string>>;

class IpReader {
public:
    StringVector Read();
};

