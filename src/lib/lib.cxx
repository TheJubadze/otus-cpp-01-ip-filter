#include "lib.hxx"

bool IpAddress::operator==(const IpAddress &r) const {
    return a == r.a && b == r.b && c == r.c && d == r.d;
}
bool IpAddress::operator!=(const IpAddress &r) const { return !(*this == r); }
bool IpAddress::operator>(const IpAddress &r) const {
    if (a > r.a) { return true; }
    else if (a == r.a) {
        if (b > r.b) { return true; }
        else if (b == r.b) {
            if (c > r.c) { return true; }
            else if (c == r.c) { return d > r.d; }
        }
    }
    return false;
}
bool IpAddress::operator<(const IpAddress &r) const { return !(*this > r) && !(*this == r); }
bool IpAddress::operator>=(const IpAddress &r) const { return *this > r || *this == r; }
bool IpAddress::operator<=(const IpAddress &r) const { return *this < r || *this == r; }

std::string IpAddress::ToString() const {
    return std::to_string(a) + '.' +
           std::to_string(b) + '.' +
           std::to_string(c) + '.' +
           std::to_string(d);
}