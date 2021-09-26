#include "lib.hxx"
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

std::vector<IpAddress> *GetIpVector() {
    std::string l;
    std::string segment;
    std::vector<std::string> strs;
    auto result = new std::vector<IpAddress>();
    while (std::getline(std::cin, l)) {
        auto ipStr = boost::split(strs, l, boost::is_any_of("\t")).at(0);
        auto ip = boost::split(strs, ipStr, boost::is_any_of("."));
        result->push_back(IpAddress(
                std::stoi(ip.at(0)),
                std::stoi(ip.at(1)),
                std::stoi(ip.at(2)),
                std::stoi(ip.at(3))));
    }
    return result;
}

void PrintIf(std::vector<IpAddress> &vec, bool (*predicate)(const IpAddress &)) {
    std::for_each(vec.begin(), vec.end(),
                  [predicate](const IpAddress &ip) {
                      if (predicate(ip))
                          std::cout << ip.ToString() << std::endl;
                  });
}

int main(int, char **) {
    auto *ips = GetIpVector();

    std::sort(ips->begin(), ips->end(), std::greater<IpAddress>());

    PrintIf(*ips, [](const IpAddress &) { return true; });
    PrintIf(*ips, [](const IpAddress &ip) { return ip.A() == 1; });
    PrintIf(*ips, [](const IpAddress &ip) { return ip.A() == 46 && ip.B() == 70; });
    PrintIf(*ips, [](const IpAddress &ip) { return ip.A() == 46 || ip.B() == 46 || ip.C() == 46 || ip.D() == 46; });

    delete ips;

    return 0;
}
