#include <gtest/gtest.h>
#include <lib.hxx>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
// Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
// Expect equality.
    EXPECT_EQ(7 * 6, 42);
};

TEST(IpAddressTest, Operator) {
    const IpAddress ipA(0, 0, 0, 0);
    const IpAddress ipB(1, 0, 0, 0);
    EXPECT_TRUE(ipA < ipB);
}