#include <gtest/gtest.h>
#include <sockpp/Sockets.h>
#include <sockpp/SocketOperations.h>

TEST(SocketTest, SocketTraits)
{
    sockpp::Socket sock(sockpp::ProtocolFamilyEnum::INET, sockpp::ProtocolTypeEnum::STREAM);

    EXPECT_EQ(sock.operation<sockpp::operations::SocketTraits>().getProtocolFamily(), sockpp::ProtocolFamilyEnum::INET);
    EXPECT_EQ(sock.operation<sockpp::operations::SocketTraits>().getProtocolType(), sockpp::ProtocolTypeEnum::STREAM);

    sockpp::Socket sock2(sockpp::ProtocolFamilyEnum::INET6, sockpp::ProtocolTypeEnum::DGRAM);

    EXPECT_EQ(sock2.operation<sockpp::operations::SocketTraits>().getProtocolFamily(), sockpp::ProtocolFamilyEnum::INET6);
    EXPECT_EQ(sock2.operation<sockpp::operations::SocketTraits>().getProtocolType(), sockpp::ProtocolTypeEnum::DGRAM);
}

