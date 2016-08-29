#include <gtest/gtest.h>
#include <sockpp/Epoller.h>
#include <sockpp/Sockets.h>
#include <sockpp/SocketOperations.h>
#include <sockpp/IPv4Addr.h>

class Subsription : public sockpp::EpollSubscription
{
public:
    Subsription(sockpp::EpollEventType _events) : events(_events) {}
    virtual void onEvent (sockpp::EpollEventType _events)
    {
        if ((unsigned)(_events & events))
        {
            ++count;
        }
    }
    unsigned getCount() { return count; }
private:
    sockpp::EpollEventType events;
    unsigned count = 0;
};


TEST(EpollerTest, SubsribeUnsubsribe)
{
    sockpp::Socket socket(sockpp::ProtocolFamilyEnum::INET, sockpp::ProtocolTypeEnum::DGRAM);
    bool bindRes = socket.operation<sockpp::operations::Bind>().addressPort(sockpp::IPv4Addr("127.0.0.1"), 32767);
    Subsription subscriptionSock1(sockpp::EpollEventType::IN);
    EXPECT_EQ(bindRes, true);

    sockpp::Epoller epoller;
    EXPECT_EQ(epoller.subscribe(subscriptionSock1, socket, sockpp::EpollEventType::IN), true);
    EXPECT_EQ(epoller.poll(0), 0);
    sockpp::Socket socket2(sockpp::ProtocolFamilyEnum::INET, sockpp::ProtocolTypeEnum::DGRAM);
    char testData[]="1234";
    EXPECT_EQ(socket.operation<sockpp::operations::Data>().sendTo("127.0.0.1", 32767, testData, sizeof(testData)), sizeof(testData));
    EXPECT_EQ(epoller.poll(1), 1);
    EXPECT_EQ(subscriptionSock1.getCount(), 1);
    EXPECT_EQ(socket.operation<sockpp::operations::Data>().sendTo("127.0.0.1", 32767, testData, sizeof(testData)), sizeof(testData));
    EXPECT_EQ(epoller.poll(1), 1);
    EXPECT_EQ(subscriptionSock1.getCount(), 2);
}
