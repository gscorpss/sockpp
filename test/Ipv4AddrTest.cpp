#include <gtest/gtest.h>
#include <sockpp/IPv4Addr.h>

TEST(Ipv4AddrTest, conversions)
{
    auto addrliteral = "127.0.0.1"_ipv4;
    
    EXPECT_EQ((std::string)addrliteral, "127.0.0.1");
    EXPECT_EQ(addrliteral.getHostAddr().s_addr, 0x7f000001);
    EXPECT_EQ(addrliteral.getNetAddr().s_addr, 0x0100007f);

    sockpp::IPv4Addr addr("127.0.0.1");
    EXPECT_EQ((std::string)addr, "127.0.0.1");
    EXPECT_EQ(addr.getHostAddr().s_addr, 0x7f000001);
    EXPECT_EQ(addr.getNetAddr().s_addr, 0x0100007f);
}
