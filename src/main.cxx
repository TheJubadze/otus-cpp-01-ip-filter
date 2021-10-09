#include "lib/lib.hxx"
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

void GetIpVector(std::vector<IpAddress> &result) {
    std::string l;
    std::vector<std::string> strs;
    while (std::getline(std::cin, l)) {
        auto ipStr = boost::split(strs, l, boost::is_any_of("\t")).at(0);
        auto ip = boost::split(strs, ipStr, boost::is_any_of("."));
        result.emplace_back(IpAddress(
                std::stoi(ip.at(0)),
                std::stoi(ip.at(1)),
                std::stoi(ip.at(2)),
                std::stoi(ip.at(3))));
    }
}

void PrintIf(std::vector<IpAddress> &vec, bool (*predicate)(const IpAddress &) = nullptr) {
    std::for_each(vec.begin(), vec.end(),
                  [predicate](const IpAddress &ip) {
                      if (predicate == nullptr || predicate(ip))
                          std::cout << ip.ToString() << std::endl;
                  });
}

int main(int, char **) {
    std::vector<IpAddress> ips;
    try {
        GetIpVector(ips);
    }
    catch (...) {
        std::cout << "Couldn't parse IP list" << std::endl;
        return 1;
    }

    std::sort(ips.begin(), ips.end(), std::greater<IpAddress>());

    PrintIf(ips);
    PrintIf(ips, [](const IpAddress &ip) { return ip.A() == 1; });
    PrintIf(ips, [](const IpAddress &ip) { return ip.A() == 46 && ip.B() == 70; });
    PrintIf(ips, [](const IpAddress &ip) { return ip.A() == 46 || ip.B() == 46 || ip.C() == 46 || ip.D() == 46; });

    return 0;
}
