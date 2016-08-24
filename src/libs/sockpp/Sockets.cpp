#include "Sockets.h"
#include "Exceptions.h"
#include <stdexcept>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <errno.h>
#include <sstream>

namespace sockpp
{

IPv4Addr operator"" _ipv4(const char* str)
{
    return IPv4Addr(str);
}

/**
 * IPv4Addr implementation
 **/
IPv4Addr::IPv4Addr(in_addr _hostAddr) : hostAddr(_hostAddr)  {}

IPv4Addr::IPv4Addr(const char* addr) { init(addr); }

IPv4Addr::IPv4Addr(const std::string& addr) { init(addr.c_str()); }

in_addr IPv4Addr::getHostAddr() const { return hostAddr; }

in_addr IPv4Addr::getNetAddr() const
{
    in_addr addr;
    addr.s_addr = htonl(hostAddr.s_addr);
    return addr;
}

void IPv4Addr::init(const char* str)
{
    if (!inet_aton(str, &hostAddr))
    {
        std::stringstream stream;
        stream << '\'' << str << "' is not valid";
        throw std::runtime_error(stream.str());
    }
    hostAddr.s_addr = ntohl(hostAddr.s_addr);
}

/**
 * Socket class implementation
 **/
Socket::Socket(ProtocolFamilyEnum family, ProtocolTypeEnum type)
{
    fd = socket((int)family, (int)type, 0);
    if (fd < 0)
    {
        std::stringstream stream;
        stream << "Unable to create socket family=" << (int)family
            << " type=" << (int)type << " with error";
        throw Exception(stream.str());
    }
}

Socket::Socket (int fd)
: fd(fd)
{
}

Socket::~Socket()
{
    if (fd >= 0)
    {
        close(fd);
    }
}

} // namespace sockpp
