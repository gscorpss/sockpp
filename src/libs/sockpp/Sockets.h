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
    Socket(Socket&& sock);
    Socket(const Socket&) = delete;

    ~Socket();

    template<class Operation>
    Operation operation() { Operation o; o.setFd(fd); return o; }

private:
    int fd;
};

} // namespace sockpp

#endif // CORE_SOCKETS_H
