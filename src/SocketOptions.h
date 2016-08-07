#ifndef CORE_NET_SOCKET_OPTIONS_H
#define CORE_NET_SOCKET_OPTIONS_H

#include <stdlib.h>

namespace core
{

class IPv4Addr;

class SocketOption
{
public:
    SocketOption() : sock(-1) {}
    void setSocket(int _sock) { sock = _sock; }
protected:
    template<class OptionValue>
    bool setOption(int level, int option, const OptionValue& optionValue, const char* optionName)
    {
        return setOptionImpl(sock, level, option, (void*)&optionValue, sizeof(optionValue), optionName);
    }
private:
    bool setOptionImpl(int sock, int level, int option, void* value, size_t valSize, const char* optionName);

    int sock;
};

struct Fragmentation : public SocketOption
{
    bool probe();
    bool allow();
    bool deny();
};

struct ReuseAddress : public SocketOption
{
    bool turnOn();
    bool turnOff();
};

struct ReusePort : public SocketOption
{
    bool turnOn();
    bool turnOff();
};

struct Broadcast : public SocketOption
{
    bool turnOn();
    bool turnOff();
};

struct Multicase : public SocketOption
{
    bool addMembership(const IPv4Addr& multiAddress, const IPv4Addr& selfAddress);
    bool dropMembership(const IPv4Addr& multiAddress, const IPv4Addr& selfAddress);
    bool setIpIface(const IPv4Addr& ifIp);
    bool setTTL(u_int8_t ttl);
};

} // namespace core

#endif // CORE_NET_SOCKET_OPTIONS_H
