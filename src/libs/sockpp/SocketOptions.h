#ifndef CORE_NET_SOCKET_OPTIONS_H
#define CORE_NET_SOCKET_OPTIONS_H

#include <stdlib.h>
#include "NetEnums.h"

namespace sockpp
{

class IPv4Addr;

namespace options
{

class SocketGetter
{
public:
    SocketGetter(): fd(-1) {}
    void setFd(int _fd) { fd = _fd; }
    int getFd() { return fd; }
private:
    int fd;
};

class SocketOption : public SocketGetter
{
protected:
    template<class OptionValue>
    bool setOption(int level, int option, const OptionValue& optionValue, const char* optionName)
    {
        return setOptionImpl(level, option, (void*)&optionValue, sizeof(optionValue), optionName);
    }
    template<class OptionValue>
    bool getOptionValue(int level, int option, const OptionValue& optionValue, const char* optionName)
    {
        return setOptionImpl(level, option, (void*)&optionValue, sizeof(optionValue), optionName);
    }
private:
    bool setOptionImpl(int level, int option, void* value, socklen_t valSize, const char* optionName);
    bool getOptionImpl(int level, int option, void* value, socklen_t valSize, const char* optionName);
};

struct Bind : public SocketGetter
{
    bool port(uint16_t port);
    bool addressPort(const IPv4Addr& addr, uint16_t port);
};

struct Listen : public SocketGetter
{
    bool listen();
    bool port(uint16_t port);
    bool addressPort(const IPv4Addr& addr, uint16_t port);
};

struct SocketTraits : public SocketGetter
{
    ProtocolFamilyEnum getProtocolFamily();
    ProtocolTypeEnum getProtocolType();
};

struct NonBlocking : public SocketGetter
{
    bool isNonBlocking();
    bool setNonBlocking();
    bool setBlocking();
    bool set(bool nonBlocking);
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

} // namespace options
} // namespace sockpp

#endif // CORE_NET_SOCKET_OPTIONS_H
