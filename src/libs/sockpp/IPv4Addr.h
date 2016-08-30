#ifndef SOCKPP_IPV4ADDR_H
#define SOCKPP_IPV4ADDR_H

#include <string>
#include <arpa/inet.h>

namespace sockpp
{

class IPv4Addr
{
public:
    explicit IPv4Addr(in_addr _hostAddr);
    IPv4Addr(const char* addr);
    IPv4Addr(const std::string& addr);
    operator std::string() const;
    in_addr getHostAddr() const;
    in_addr getNetAddr() const;
private:
    void init(const char* str);

    in_addr netAddr;
};

} // namespace sockpp

inline sockpp::IPv4Addr operator"" _ipv4(const char* str, size_t s) { return sockpp::IPv4Addr(str); }


#endif //SOCKPP_IPV4ADDR_H
