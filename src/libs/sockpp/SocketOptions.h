#ifndef CORE_NET_SOCKET_OPTIONS_H
#define CORE_NET_SOCKET_OPTIONS_H

#include <stdlib.h>
#include "NetEnums.h"

namespace sockpp
{

class IPv4Addr;

namespace options
{

class SocketOption
{
public:
    SocketOption() : fd(-1) {}
    void setFd(int _fd) { fd = _fd; }
protected:
    template<class OptionValue>
    bool setOption(int level, int option, const OptionValue& optionValue, const char* optionName)
    {
        return setOptionImpl(fd, level, option, (void*)&optionValue, sizeof(optionValue), optionName);
    }
    int getFd() { return fd; }
private:
    bool setOptionImpl(int fd, int level, int option, void* value, size_t valSize, const char* optionName);

    int fd;
};

struct Bind : public SocketOption
{
    bool port(uint16_t port);
    bool addressPort(const IPv4Addr& addr, uint16_t port);
};

struct Listen : public SocketOption
{
    bool listen();
    bool port(uint16_t port);
    bool addressPort(const IPv4Addr& addr, uint16_t port);

};

struct ProtocolFamily : public SocketOption
{
    ProtocolFamilyEnum get();
};

struct ProtocolType : public SocketOption
{
    ProtocolTypeEnum get();
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
