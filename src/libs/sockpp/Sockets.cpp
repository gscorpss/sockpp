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

Socket::Socket(Socket&& sock)
: fd(sock.fd)
{
    sock.fd = -1;
}

Socket::~Socket()
{
    if (fd >= 0)
    {
        close(fd);
    }
}

} // namespace sockpp
