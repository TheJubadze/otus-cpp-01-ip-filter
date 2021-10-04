#include <gtest/gtest.h>
#include <lib.hxx>

class IpAddressTestFixture
        : public ::testing::TestWithParam<std::tuple<bool (*)(), bool>> {
};

TEST_P(IpAddressTestFixture, OperatorsTests) {
    auto[predicate, expected] = GetParam();

    ASSERT_EQ(expected, predicate());
}

INSTANTIATE_TEST_CASE_P
(
        OperatorLessThanTests,
        IpAddressTestFixture,
        ::testing::Values(
                std::make_tuple([]() { return IpAddress(0, 0, 0, 0) > IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 0) < IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 0) == IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 0) >= IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 0) <= IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 0) != IpAddress(0, 0, 0, 0); }, false),

                std::make_tuple([]() { return IpAddress(1, 0, 0, 0) > IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 1, 0, 0) > IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 1, 0) > IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 1) > IpAddress(0, 0, 0, 0); }, true),

                std::make_tuple([]() { return IpAddress(1, 0, 0, 0) >= IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 1, 0, 0) >= IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 1, 0) >= IpAddress(0, 0, 0, 0); }, true),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 1) >= IpAddress(0, 0, 0, 0); }, true),

                std::make_tuple([]() { return IpAddress(1, 0, 0, 0) < IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 1, 0, 0) < IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 0, 1, 0) < IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 1) < IpAddress(0, 0, 0, 0); }, false),

                std::make_tuple([]() { return IpAddress(1, 0, 0, 0) <= IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 1, 0, 0) <= IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 0, 1, 0) <= IpAddress(0, 0, 0, 0); }, false),
                std::make_tuple([]() { return IpAddress(0, 0, 0, 1) <= IpAddress(0, 0, 0, 0); }, false)
        ));

TEST(IpAddressTest, Operator) {
    const IpAddress ipA(0, 0, 0, 0);
    const IpAddress ipB(1, 0, 0, 0);
    EXPECT_TRUE(ipA < ipB);
}