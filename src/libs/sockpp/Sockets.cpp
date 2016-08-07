#include "Sockets.h"
#include <stdexcept>
#include <iostream>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>
#include <errno.h>

namespace sockpp
{
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
        throw std::runtime_error(stream.c_str());
    }
}

/**
 * Socket class implementation
 **/
Socket::Socket(ProtocolFamilyEnum family, ProtocolTypeEnum type)
{
    fd = socket(family, type, 0);
    if (fd < 0)
    {
        std::stringstream stream;
        stream << "Unable to create socket family=" << (int)family
            << " type=" << type << " with error";
        throw std::runtime_error(stream.c_str());
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

bool Socket::setNonBlocking()
{
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0)
    {
        std::cerr << "Unable to get flags : (" << errno << ") " << strerror(errno) << std::endl;
        return false;
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == 0)
        return true;
    std::cerr << "Unable to set flags : (" << errno << ") " << strerror(errno) << std::endl;
    return false;
}

} // namespace sockpp
