#pragma once

#include <memory>
#include <vector>
#include "IpAddress.h"
#include "IpReader.h"

using IpVector = std::unique_ptr<std::vector<IpAddress>>;

class IpParser {
public:
    static IpVector Parse(const StringVector &);
};

