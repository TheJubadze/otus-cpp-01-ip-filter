#pragma once

#include <iostream>

int version();

class IpAddress {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
public:
    IpAddress(unsigned short a, unsigned short b, unsigned short c, unsigned short d)
            : a(a), b(b), c(c), d(d) {};
    std::string ToString() const;
    bool operator==(const IpAddress &r) const;
    bool operator!=(const IpAddress &r) const;
    bool operator>(const IpAddress &r) const;
    bool operator<(const IpAddress &r) const;
    bool operator>=(const IpAddress &r) const;
    bool operator<=(const IpAddress &r) const;
    unsigned short A() const { return a; };
    unsigned short B() const { return b; };
    unsigned short C() const { return c; };
    unsigned short D() const { return d; };
};
