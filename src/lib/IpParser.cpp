#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "IpParser.h"


IpAddress CreateIpAddress(std::string s) {
    std::vector<std::string> strs;
    auto ipStr = boost::split(strs, s, boost::is_any_of("\t")).at(0);
    boost::split(strs, ipStr, boost::is_any_of("."));

    auto ip = IpAddress(
            std::stoi(strs.at(0)),
            std::stoi(strs.at(1)),
            std::stoi(strs.at(2)),
            std::stoi(strs.at(3)));

    return ip;
}

IpVector IpParser::Parse(const StringVector &vec) {
    auto ipVec = std::make_unique<std::vector<IpAddress>>();
    for (const auto &ipStr: *vec) {
        ipVec->emplace_back(CreateIpAddress(ipStr));
    }
    //std::transform(vec->begin(), vec->end(), ipVec->begin(), CreateIpAddress);    //Doesn't work for some reason: SegFault
    return ipVec;
}
