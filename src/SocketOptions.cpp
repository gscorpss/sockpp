#include "SocketOptions.h"
#include "Sockets.h"
#include <fcntl.h>
#include <arpa/inet.h>
#include <cstring>
#include <errno.h>
#include <iostream>

namespace core
{

bool SocketOption::setOptionImpl(int sock, int level, int option, void* value, size_t valSize, const char* optionName)
{
    if (!setsockopt (sock, level, option, value, valSize))
        return true;
    std::cerr << "Unable to set option '" << optionName << "' with error: (" << errno << ") " << strerror(errno) << std::endl;
    return false;
}

bool Fragmentation::probe()
{
    return this->setOption(SOL_IP, IP_MTU_DISCOVER, int(IP_PMTUDISC_PROBE), "probe ip packets fragmentation");
}

bool Fragmentation::allow()
{
    return this->setOption(SOL_IP, IP_MTU_DISCOVER, int(IP_PMTUDISC_WANT), "allow ip packets fragmentation");
}

bool Fragmentation::deny()
{
    return this->setOption(SOL_IP, IP_MTU_DISCOVER, int(IP_PMTUDISC_DO), "deny ip packets fragmentation");
}


bool ReuseAddress::turnOn()
{
    return this->setOption(SOL_SOCKET, SO_REUSEADDR, int(1), "turn on reuse address");
}

bool ReuseAddress::turnOff()
{
    return this->setOption(SOL_SOCKET, SO_REUSEADDR, int(0), "turn off reuse address");
}

bool ReusePort::turnOn()
{
    return this->setOption(SOL_SOCKET, SO_REUSEPORT, int(1), "turn on reuse port");
}

bool ReusePort::turnOff()
{
    return this->setOption(SOL_SOCKET, SO_REUSEPORT, int(0), "turn off reuse port");
}

bool Broadcast::turnOn()
{
    return this->setOption(SOL_SOCKET, SO_BROADCAST, int(1), "turn on broadcast");
}

bool Broadcast::turnOff()
{
    return this->setOption(SOL_SOCKET, SO_BROADCAST, int(0), "turn off broadcast");
}


bool Multicase::addMembership(const IPv4Addr& multiAddress, const IPv4Addr& selfAddress)
{
    ip_mreq mReq;
    mReq.imr_multiaddr = multiAddress.getHostAddr();
    mReq.imr_interface = selfAddress.getHostAddr();
    return this->setOption(IPPROTO_IP, IP_ADD_MEMBERSHIP, mReq, "join multicast group");
}
bool Multicase::dropMembership(const IPv4Addr& multiAddress, const IPv4Addr& selfAddress)
{
    ip_mreq mReq;
    mReq.imr_multiaddr = multiAddress.getHostAddr();
    mReq.imr_interface = selfAddress.getHostAddr();
    return this->setOption(IPPROTO_IP, IP_DROP_MEMBERSHIP, mReq, "leave multicast group");
}
bool Multicase::setIpIface(const IPv4Addr& ifIp)
{
    in_addr addr;
    addr = ifIp.getHostAddr();
    return this->setOption(IPPROTO_IP, IP_MULTICAST_IF, addr, "set multicast interface");
}
bool Multicase::setTTL(u_int8_t ttl)
{
    return this->setOption(IPPROTO_IP, IP_MULTICAST_TTL, ttl, "set multicast ttl");
}

} // namespace core
