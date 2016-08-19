#ifndef CORE_SOCKETS_H
#define CORE_SOCKETS_H

#include <string>
#include <arpa/inet.h>
#include "NetEnums.h"

namespace sockpp
{

class IPv4Addr
{
public:
    explicit IPv4Addr(in_addr _hostAddr);
    IPv4Addr(const char* addr);
    IPv4Addr(const std::string& addr);
    in_addr getHostAddr() const;
    in_addr getNetAddr() const;
private:
    void init(const char* str);

    in_addr hostAddr;
};


class Socket
{
public:
    Socket(int fd);
    Socket(ProtocolFamilyEnum family, ProtocolTypeEnum type);

    ~Socket();

    int getFd() { return fd; }

    template<class Option>
    Option option() { Option o; o.setFd(fd); return o; }

private:
    int fd;
};

} // namespace sockpp

#endif // CORE_SOCKETS_H
