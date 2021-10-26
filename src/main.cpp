#include "lib/IpAddress.h"
#include "lib/IpReader.h"
#include "lib/IpParser.h"
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

void PrintIf(IpVector &vec, bool (*predicate)(const IpAddress &) = nullptr) {
    std::for_each(vec->begin(), vec->end(),
                  [predicate](const IpAddress &ip) {
                      if (predicate == nullptr || predicate(ip))
                          std::cout << ip.ToString() << std::endl;
                  });
}

int main(int, char **) {
    IpReader ipReader;
    IpVector ips;
    try {
        auto strings = ipReader.Read();
        ips = IpParser::Parse(strings);
    }
    catch (std::exception &e) {
        std::cout << "Couldn't parse IP list: " << e.what() << std::endl;
        return 1;
    }

    std::sort(ips->begin(), ips->end(), std::greater<>{});

    PrintIf(ips);
    PrintIf(ips, [](const IpAddress &ip) { return ip.A() == 1; });
    PrintIf(ips, [](const IpAddress &ip) { return ip.A() == 46 && ip.B() == 70; });
    PrintIf(ips, [](const IpAddress &ip) { return ip.A() == 46 || ip.B() == 46 || ip.C() == 46 || ip.D() == 46; });

    return 0;
}
