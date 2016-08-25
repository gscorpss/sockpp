#ifndef CORE_SOCKETS_H
#define CORE_SOCKETS_H

#include "NetEnums.h"

namespace sockpp
{

class Socket
{
public:
    Socket(int fd);
    Socket(ProtocolFamilyEnum family, ProtocolTypeEnum type);

    ~Socket();

    int getFd() { return fd; }

    template<class Operation>
    Operation operation() { Operation o; o.setFd(fd); return o; }

private:
    int fd;
};

} // namespace sockpp

#endif // CORE_SOCKETS_H
