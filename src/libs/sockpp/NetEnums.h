#ifndef CORE_NET_ENUMS_H
#define CORE_NET_ENUMS_H

#include <arpa/inet.h>

namespace sockpp
{

enum class ProtocolFamilyEnum : int
{
    NOTDEFINED = -1,
    /// \brief Local communication
    UNIX = AF_UNIX,
    /// \brief Local communication
    LOCAL = AF_LOCAL,
    /// \brief IPv4 Internet protocols
    INET = AF_INET,
    /// \brief IPv6 Internet protocols
    INET6 = AF_INET6,
    /// \brief IPX - Novell protocols
    IPX= AF_IPX,
    /// \brief Kernel user interface device
    NETLINK = AF_NETLINK,
    /// \brief ITU-T X.25 / ISO-8208 protocol
    X25 = AF_X25,
    /// \brief Amateur radio AX.25 protocol
    AX25 = AF_AX25,
    /// \brief Access to raw ATM PVCs
    ATMPVC = AF_ATMPVC,
    /// \brief AppleTalk
    APPLETALK = AF_APPLETALK,
    /// \brief Low level packet interface
    PACKET = AF_PACKET
};

enum class ProtocolTypeEnum : int
{
    NOTDEFINED = -1,
    STREAM = SOCK_STREAM,
    DGRAM = SOCK_DGRAM,
    SEQPACKET = SOCK_SEQPACKET,
    RAW = SOCK_RAW,
    RDM = SOCK_RDM,
    PACKET = SOCK_PACKET
};

} // namespace sockpp

#endif // CORE_NET_ENUMS_H
